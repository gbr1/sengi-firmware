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
#ifndef __PID_H__
#define __PID_H__

#include "Arduino.h"

#define MAXVALUE 65535

class Pid{
private:
  float kp;
  float ki;
  float kd;
  float c_out;
  float c_in;
  float c_ref;
  float error;
  float p_error;
  float c_i;
  float c_d;

  float maxv;
  float minv;

  float checkMaxMin(float,float,float);

public:
  Pid(float, float, float);

  void setKp(float k){kp=k;}
  void setKi(float k){ki=k;}
  void setKd(float k){kd=k;}
  void setTunings(float p, float i, float d){kp=p; ki=i; kd=d;}

  void setReference(float r){c_ref=r;}
  void setOutputLimits(float min, float max){maxv=max; minv=min;}

  float getKp(){return kp;}
  float getKi(){return ki;}
  float getKd(){return kd;}

  void setCin(float c){c_in=c;}
  float getCout(){ return c_out;}

  void reset(){error=0; p_error=0; c_out=0; c_in=0;}

  float compute();


};

#endif
