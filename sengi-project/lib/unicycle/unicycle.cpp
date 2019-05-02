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
#include "unicycle.h"

Unicycle::Unicycle(){
  motor_A.invertPolarity(false);
  motor_B.invertPolarity(false);
  inverseKinematic(0,0);

  wheelradius2=WHEEL_RADIUS/2.0;  //   r/2
  wheelbaseratio=WHEEL_RADIUS/WHEEL_BASE;  //  r/d


  x=0;
  y=0;
  theta=0;
  d_linear=0;
  d_theta=0;

}


void Unicycle::update(){
  motor_A.update();
  motor_B.update();
}

void Unicycle::inverseKinematic(float linear, float angular){
  motor_A.setSetpoint((linear+angular*WHEEL_BASE_RADIUS)/WHEEL_RADIUS);  //right
  motor_B.setSetpoint((linear-angular*WHEEL_BASE_RADIUS)/WHEEL_RADIUS);  //left
}

void Unicycle::forwardKinematic(){
  prev_x=x;
  prev_y=y;
  prev_theta=theta;

  phiR=motor_A.getTotalRad();
  motor_A.resetTotalRad();
  phiL=motor_B.getTotalRad();
  motor_B.resetTotalRad();

  d_linear=wheelradius2*(phiR+phiL);
  d_theta=wheelbaseratio*(phiR-phiL);

  theta=prev_theta+d_theta;
  if (d_theta==0){
    x=prev_x+d_linear*sin(prev_theta);
    y=prev_y+d_linear*cos(prev_theta);
  }
  else{
    dldt=d_linear/d_theta;
    x=prev_x+dldt*(sin(theta)-sin(prev_theta));
    y=prev_y+dldt*(cos(theta)-cos(prev_theta));
  }
}
