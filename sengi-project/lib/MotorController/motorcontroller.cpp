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
#include "motorcontroller.h"

MotorController::MotorController(uint8 _pinM1, uint8 _pinM2,
        uint8 _pinE1, uint8 _pinE2, timer_dev* _timenc, unsigned char _modec,
        int _cpr, float _gear):
        DCMotor(_pinM1, _pinM2),
        Encoder(_timenc, _modec, _pinE1, _pinE2){

      //default tuning
      kp=DEFAULT_KP;
      ki=DEFAULT_KI;
      kd=DEFAULT_KD;

      //setpoint is 0 rad/s
      setpoint=0;

      pid.setTunings(kp,ki,kd);
      pid.setOutputLimits(-65535,65535);
      pid.setReference(setpoint);

      cpr=_cpr;
      gear=_gear;
      ratio=2*PI/((float)cpr*gear)*1000.0;
      count_ratio=2*PI/((float)cpr*gear);

      total_count=0;

};

float MotorController::evalRadians(int count){
    return ratio*(float)count;
}

void MotorController::update(){
  count = getCount();
  reset();
  radats=evalRadians(count);
  total_count+=count_ratio*count;
  pid.setCin(radats);
  action=pid.compute();
  setSpeed(action);
}

void MotorController::setSetpoint(float s){
  setpoint=s;
  pid.setReference(setpoint);
}
