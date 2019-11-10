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
#include "pid.h"

Pid::Pid(float _kp, float _ki, float _kd){
  kp=_kp;
  ki=_ki;
  kd=_kd;

  c_ref=0;
  c_in=0;
  c_out=0;
  error=0;
  p_error=0;

  c_i=0;
  c_d=0;

  maxv=MAXVALUE;
  minv=-MAXVALUE;

}

float Pid::compute(){
  error=c_ref-c_in;
  c_i=c_i+(ki*error);
  c_i=checkMaxMin(c_i, minv, maxv);
  c_d=kd*(error-p_error);
  c_out=kp*error+c_i+c_d;
  c_out=checkMaxMin(c_out, minv, maxv);
  p_error=error;
  return c_out;
}

float Pid::checkMaxMin(float v, float min, float max){
  if (v>max){
    return max;
  }
  if (v<min){
    return min;
  }
  return v;
}
