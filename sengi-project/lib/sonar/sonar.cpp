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
#include "sonar.h"


timer_dev * Sonar::tim_sonar;
uint8 Sonar::phase;
boolean Sonar::ready;
int Sonar::prevtime;
int Sonar::sonarUS;

Sonar::Sonar(uint8 _trig, uint8 _echo, timer_dev * _t){
  ready=false;
  trig=_trig;
  pinMode(trig,OUTPUT);
  digitalWrite(trig,LOW);
  echo=_echo;
  pinMode(echo,INPUT_PULLUP);

  tim_sonar = _t;

  timer_init(tim_sonar);
  (tim_sonar->regs).gen->CCMR1 = 0x00F1;
  (tim_sonar->regs).gen->CCMR2 = 0x0000;
  (tim_sonar->regs).gen->CCER  = 0x0001;
  (tim_sonar->regs).gen->SMCR  = 0x0000;
  (tim_sonar->regs).gen->CR1   = 0x0001;
  (tim_sonar->regs).gen->CR2   = 0x0000;
  (tim_sonar->regs).gen->PSC   = 24; //36 if 72MHz

  timer_attach_interrupt(tim_sonar, TIMER_CC1_INTERRUPT, Sonar::sonarInterrupt);

  timer_resume(tim_sonar);
}

void Sonar::sonarInterrupt(void){
  phase = (tim_sonar->regs).gen->CCER & 0x0002; //get edge for the interrupt
  if (phase==0){
    //prevtime=(Sonar::tim_sonar->regs).gen->CCR1;
    timer_set_count(tim_sonar, 0);
    (tim_sonar->regs).gen->CCER |= 0x0002; //set falling
  }else{
    sonarUS=(((tim_sonar->regs).gen->CCR1)/*-prevtime*/)/2;
    //timer_set_count(tim_sonar, 0);
    (tim_sonar->regs).gen->CCER &= ~0x0002; //set rising
    ready=true;
  }
}

boolean Sonar::isReady(){
  return ready;
}

float Sonar::getDistance(){
  if (ready){
    return ((float)sonarUS)*0.01715;
  }
  else{
    return -1.0;
  }
}

void Sonar::startReading(){
  ready=false;
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
}

void Sonar::reset(){
  ready=false;
}
