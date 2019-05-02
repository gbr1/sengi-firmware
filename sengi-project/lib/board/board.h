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
#ifndef __BOARD_H__
#define __BOARD_H__

#include "Arduino.h"
#include "definitions.h"
#include "sonar.h"
#include "motorcontroller.h"


class Board{

private:
  float battery_voltage;



public:
  Board();

  //intialize the board.
  void init();

  //onboard led methods.
  void onBoardLed_ON();
  void onBoardLed_OFF();

  //warning onboard led methods.
  void warningLed_ON();
  void warningLed_OFF();

  void enableMotors();
  void disableMotors();


  MotorController motor_Right{MOTOR_A_CH1, MOTOR_A_CH2, MOTOR_A_EN1, MOTOR_A_EN2,
                          MOTOR_A_TIM, COUNT_BOTH_CHANNELS,
                          MOTOR_A_CPR, MOTOR_A_GRR};

  MotorController motor_Left{MOTOR_B_CH1, MOTOR_B_CH2, MOTOR_B_EN1, MOTOR_B_EN2,
                          MOTOR_B_TIM, COUNT_BOTH_CHANNELS,
                          MOTOR_B_CPR, MOTOR_B_GRR};

  void motors_update();

  void reset();

  float getVoltage();




  Sonar sonar{PB11,PA0,TIMER2};









};

#endif
