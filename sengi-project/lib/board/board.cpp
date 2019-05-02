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
#include "board.h"

Board::Board(){
  //setup for onboard led pin
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(LED_WARN,OUTPUT);
  pinMode(MOTOR_SLEEP,OUTPUT);

  motor_Left.invertPolarity(false);
  motor_Right.invertPolarity(false);


  pinMode(BATT_READ, INPUT_ANALOG);
  pinMode(BATT_EN,OUTPUT);
  digitalWrite(BATT_EN,LOW);
  battery_voltage=0.0;
/*
  HardwareTimer hwt(3);
  hwt.pause();
  hwt.setPrescaleFactor(48); //1
  hwt.setCount(0);
  hwt.setOverflow(99);   //4000
  hwt.setCompare(TIMER_CH3, 1000);
  hwt.refresh();
  hwt.resume();
*/

}

void Board::init(){
  //onboard led
  onBoardLed_OFF();
  warningLed_OFF();
  disableMotors();
}

//onboard led
void Board::onBoardLed_ON(){
  digitalWrite(LED_BUILTIN, LOW);
}

void Board::onBoardLed_OFF(){
  digitalWrite(LED_BUILTIN, HIGH);
}

void Board::warningLed_ON(){
  digitalWrite(LED_WARN, LOW);
}

void Board::warningLed_OFF(){
  digitalWrite(LED_WARN, HIGH);
}

void Board::enableMotors(){
  digitalWrite(MOTOR_SLEEP, HIGH);
}

void Board::disableMotors(){
  digitalWrite(MOTOR_SLEEP, LOW);
}

void Board::motors_update(){
  motor_Left.update();
  motor_Right.update();
}

void Board::reset(){
  motor_Left.pid.reset();
  motor_Left.resetTotalCount();
  motor_Right.pid.reset();
  motor_Right.resetTotalCount();
}

float Board::getVoltage(){
  //digitalWrite(BATT_EN, HIGH);
  //delay_us(5);
  //battery_voltage=(analogRead(BATT_READ)/4095.0);//*7.40/282.0;//3112.0;
  //digitalWrite(BATT_EN, LOW);
  battery_voltage=analogRead(BATT_READ)/3582.0*8.21;
  return battery_voltage;
}
