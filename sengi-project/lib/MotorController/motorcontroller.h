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
#ifndef __MOTORCONTROLLER_H__
#define __MOTORCONTROLLER_H__

#include "dcmotor.h"
#include "encoder.h"
#include "pid.h"
#include "definitions.h"

class MotorController: public DCMotor, public Encoder{
private:
  //pid tuning parameters
  float kp;
  float ki;
  float kd;

  float setpoint;   //rad/s by high level controller
  float action;     //output to drive motors
  float radats;     //rad/s from encoder

  int   cpr;
  float gear;
  float ratio;
  float count_ratio;

  int   count;

  float total_count;

public:
  MotorController(uint8 _pinM1, uint8 _pinM2, uint8 _pinE1, uint8 _pinE2,
                  timer_dev* _timenc, unsigned char _modec,
                  int _cpr, float _gear);

  Pid pid{kp, ki, kd};

  float evalRadians(int);
  void update();
  void setSetpoint(float);
  float getReference(){return setpoint;}
  float getRadats(){ return radats;}
  float getAction(){ return action;}

  void resetTotalCount(){total_count=0;}
  float getTotalCount(){return total_count;}

};

#endif
