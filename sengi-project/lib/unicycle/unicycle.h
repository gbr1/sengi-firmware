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
#ifndef __UNICYCLE_H__
#define __UNICYCLE_H__

#include "Arduino.h"
#include "definitions.h"
#include "motorcontroller.h"
#include "robot_definitions.h"
#include "math.h"

class Unicycle{

private:
  float x;
  float y;
  float theta;

  float d_linear;
  float d_theta;

  float prev_x;
  float prev_y;
  float prev_theta;

  float dldt;

  float phiR;
  float phiL;

  float wheelradius2;
  float wheelbaseratio;

public:
  Unicycle();
  void update();


  void inverseKinematic(float , float);
  void forwardKinematic();

  float getX(){return x;}
  float getY(){return y;}
  float getTheta(){return theta;}
  float getLinear(){return d_linear;}
  float getAngular(){return d_theta;}





  MotorController motor_A{MOTOR_A_CH1, MOTOR_A_CH2, MOTOR_A_EN1, MOTOR_A_EN2,
                          MOTOR_A_TIM, COUNT_BOTH_CHANNELS,
                          MOTOR_A_CPR, MOTOR_A_GRR};

  MotorController motor_B{MOTOR_B_CH1, MOTOR_B_CH2, MOTOR_B_EN1, MOTOR_B_EN2,
                          MOTOR_B_TIM, COUNT_BOTH_CHANNELS,
                          MOTOR_B_CPR, MOTOR_B_GRR};
};

#endif
