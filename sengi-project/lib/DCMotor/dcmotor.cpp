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
#include "dcmotor.h"

DCMotor::DCMotor(uint8 _pinA, uint8 _pinB){
  pinA=_pinA;
  pinB=_pinB;
  pinMode(pinA,PWM);
  pinMode(pinB,PWM);

  pwmWrite(pinA,0);
  pwmWrite(pinB,0);
}

void DCMotor::setSpeed(int32_t val){
  if (val>=0){
    pwmWrite(pinA, val);
    pwmWrite(pinB, 0);
  }
  else{
    pwmWrite(pinA, 0);
    pwmWrite(pinB, -val);
  }
}

void DCMotor::setStop(){
  pwmWrite(pinA,0);
  pwmWrite(pinB,0);
}
