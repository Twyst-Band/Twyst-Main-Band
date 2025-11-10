#ifndef TOUCH_H
#define TOUCH_H

#include <Arduino.h>
#include "Touch_Driver.h"

void initTouch();

void Touch_INT_callback();
// void On_Swipe_Up();
// void On_Swipe_Down();
// void On_Swipe_Left();
// void On_Swipe_Right();
// void On_Click();
// void On_Double_Click();
// void On_Long_Press();

void On_Press();
void On_Release();
void On_Move();

void Update_Coords();
void Touch_Loop();

#endif