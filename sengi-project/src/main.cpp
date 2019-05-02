/*
 * The MIT License
 *
 * Copyright (c) 2019 Giovanni di Dio Bruno https://gbr1.github.io
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#include <Arduino.h>
#include <ros.h>
#include <sengi_ros/Drive.h>
#include <sengi_ros/Feedback.h>
#include <sengi_ros/PidConfiguration.h>
#include <sengi_ros/Status.h>
#include <board.h>


Board sengi;
ros::NodeHandle  nh;

//subscriber for controlling joints
void motors(const sengi_ros::Drive& cmd_msg);
ros::Subscriber<sengi_ros::Drive> jointdrive("/sengi/cmd_drive", motors);

//publisher for joints feedback
sengi_ros::Feedback robot_state;
ros::Publisher jointstate("/sengi/feedback", &robot_state);

//subscriber for updating pid configuration
void pid_configuration(const sengi_ros::PidConfiguration& pid_msg);
ros::Subscriber<sengi_ros::PidConfiguration> pid_config("/sengi/pid", pid_configuration);

bool isMotorL0=true;
bool isMotorR0=true;

sengi_ros::Status battery_state;
ros::Publisher batterystate("/sengi/status", &battery_state);
float voltage=0;
char log_measure[8];
char log_msg[30];

uint16 timer_led=0;
uint16 timer_led_period=SLOWBLINK;

uint16 timer_joint=0;

uint16 timer_battery=0;

void led_blink();

//systick interrupt function
void tick();
void null_tick(){}

void update_joints();

void battery_monitor();

void setup() {
    // put your setup code here, to run once:
    sengi.init();
    Serial.begin(115200);
    systick_attach_callback(tick);


    nh.initNode();
    nh.subscribe(jointdrive);
    nh.advertise(jointstate);
    nh.advertise(batterystate);
    //nh.subscribe(pid_config);

}



void loop() {
  //waiting for connection

  //motor driver is disabled
  sengi.disableMotors();

  //everything in the math model is at 0



  //slow blinking -> sengi is not connected
  timer_led_period=SLOWBLINK;

  while(!nh.connected()){
    nh.spinOnce();
    led_blink();
    battery_monitor();
  }

  //connection is ok
  nh.loginfo("Sengi board is connected!");
  timer_led_period=FASTBLINK;

  //enable motor driver
  sengi.enableMotors();

  //do stuffs
  while (nh.connected()){
    update_joints();
    led_blink();
    battery_monitor();
    nh.spinOnce();
    //delay(1);
  }
  sengi.disableMotors();
  sengi.reset();

}


//this function is needed to update everything every 1ms
void tick(void){
  sengi.motors_update();
  /*if (isMotorL0==false){
    sengi.motor_Left.update();
  }
  else{
    sengi.motor_Left.setStop();
  }
  if (isMotorR0==false){
    sengi.motor_Right.update();
  }
  else{
    sengi.motor_Right.setStop();
  }
  */
  timer_led++;
  timer_joint++;
  timer_battery++;
}

//this function is needed to blink onboard led
void led_blink(){
  if (timer_led<timer_led_period){
    sengi.onBoardLed_ON();
  }
  if (timer_led>=timer_led_period){
    sengi.onBoardLed_OFF();
  }
  if (timer_led>(timer_led_period*2)){
    timer_led=0;
  }
}

//this funtion is needed to update motors setpoints
void motors(const sengi_ros::Drive& cmd_msg){
  systick_attach_callback(NULL);
  /*if (cmd_msg.drivers[0]==0){
      isMotorL0=true;
      sengi.motor_Left.setSetpoint(0);
      sengi.motor_Left.setStop();
      sengi.motor_Left.pid.reset();
  }else{
    isMotorL0=false;*/
    sengi.motor_Left.setSetpoint(cmd_msg.drivers[0]);
  /*}
  if (cmd_msg.drivers[1]==0){
    isMotorR0=true;
    sengi.motor_Right.setSetpoint(0);
    sengi.motor_Right.setStop();
    sengi.motor_Right.pid.reset();
  }else{
    isMotorR0=false;*/
    sengi.motor_Right.setSetpoint(cmd_msg.drivers[1]);
  /*}*/
  systick_attach_callback(tick);
  //if ((cmd_msg.drivers[0]==0)&&(cmd_msg.drivers[1]==0)){}
}

//publish joint feedback
void update_joints(){
  if (timer_joint>20/*10*//*20*/){  //20hz for ros control

    robot_state.header.frame_id = "base_link";
    robot_state.header.stamp=nh.now();

    robot_state.drivers[0].measured_velocity = sengi.motor_Left.getRadats();
    robot_state.drivers[0].measured_travel = sengi.motor_Left.getTotalCount();

    robot_state.drivers[1].measured_velocity = sengi.motor_Right.getRadats();
    robot_state.drivers[1].measured_travel = sengi.motor_Right.getTotalCount();

    jointstate.publish(&robot_state);

    timer_joint=0;
  }
}

void pid_configuration(const sengi_ros::PidConfiguration& pid_msg){
  sengi.motor_Left.pid.setKp(pid_msg.pid[0].kp);
  sengi.motor_Left.pid.setKi(pid_msg.pid[0].ki);
  sengi.motor_Left.pid.setKd(pid_msg.pid[0].kd);
  sengi.motor_Right.pid.setKp(pid_msg.pid[1].kp);
  sengi.motor_Right.pid.setKi(pid_msg.pid[1].ki);
  sengi.motor_Right.pid.setKd(pid_msg.pid[1].kd);
}

void battery_monitor(){
  if (timer_battery>10000){
    voltage=sengi.getVoltage();
    if (nh.connected()){
      battery_state.header.frame_id = "base_link";
      battery_state.header.stamp=nh.now();

      battery_state.battery_voltage = voltage;
      batterystate.publish(&battery_state);
    }
    //dtostrf(voltage, 6, 2, log_measure);
    if (voltage<6.0){
      if (nh.connected()){
        nh.logwarn("WARNING - BATTERY TOO LOW");
      }
      sengi.warningLed_ON();
    }
    else{
      sengi.warningLed_OFF();
    }

    timer_battery=0;
  }
}
