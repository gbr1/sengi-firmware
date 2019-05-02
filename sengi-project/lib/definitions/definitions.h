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
#ifndef __DEFINITIONS__H__
#define __DEFINITIONS__H__


//onboard led
#define LED_BUILTIN PC13
#define LED_WARN    PA10

//motor A right
#define MOTOR_A_CH1 PA6
#define MOTOR_A_CH2 PA7
#define MOTOR_A_EN1 PB6
#define MOTOR_A_EN2 PB7
#define MOTOR_A_CPR 360
#define MOTOR_A_TIM TIMER4
#define MOTOR_A_GRR 150.58

//motor B left
#define MOTOR_B_CH1 PB1
#define MOTOR_B_CH2 PB0
#define MOTOR_B_EN1 PA8
#define MOTOR_B_EN2 PA9
#define MOTOR_B_CPR 360
#define MOTOR_B_TIM TIMER1
#define MOTOR_B_GRR 150.58

#define MOTOR_SLEEP PB8



//controllers default parameters
#define DEFAULT_KP 10000.0
#define DEFAULT_KI 1000.0
#define DEFAULT_KD 1.0


#define FASTBLINK  100
#define SLOWBLINK  500


//bms pins
#define BATT_EN   PA4
#define BATT_READ PA5


#endif
