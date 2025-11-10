#include "touch.h"

bool touchFlag = false;

bool pressing = false;

void initTouch()
{
    XY.mode = 0;
    XY.x_point = 0;
    XY.y_point = 0;

    if (Touch_1IN28_init(XY.mode) == true)
    {
        Serial.println("Touch initialized successfully.");
    }
    else
    {
        Serial.println("Touch initialization failed.");
    }

    delay(100);

    pinMode(TP_INT_PIN, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(TP_INT_PIN), Touch_INT_callback, FALLING);
}

void Touch_INT_callback()
{
    touchFlag = true;
}

void Touch_Loop()
{
    if (pressing) {
        Update_Coords();
        On_Move();
    }

    if (!touchFlag)
        return;

    byte isPressing = DEV_I2C_Read_Byte(address, 0x02);

    if (isPressing == 0x00) {
        if (pressing) {
            On_Release();
            pressing = false;
        }
    } else if (!pressing) {
        pressing = true;
        Update_Coords();
        On_Press();
    }

    // switch (gesture)
    // {
    // case UP:
    //     On_Swipe_Up();
    //     break;
    // case DOWN:
    //     On_Swipe_Down();
    //     break;
    // case LEFT:
    //     On_Swipe_Left();
    //     break;
    // case RIGHT:
    //     On_Swipe_Right();
    //     break;
    // case CLICK:
    //     On_Click();
    //     break;
    // case DOUBLE_CLICK:
    //     On_Double_Click();
    //     break;
    // case LONG_PRESS:
    //     On_Long_Press();
    //     break;
    // default:
    //     break;
    // }

    touchFlag = false;
}

void Update_Coords()
{
    Touch_1IN28_Get_Point();
}

void On_Press()
{
    Serial.print("Screen Pressed at: X=");
    Serial.print(XY.x_point);
    Serial.print(" Y=");
    Serial.println(XY.y_point);
}

void On_Release()
{
    Serial.print("Screen Released at: X=");
    Serial.print(XY.x_point);
    Serial.print(" Y=");
    Serial.println(XY.y_point);
}

void On_Move()
{
    Serial.print("Touch Move to: X=");
    Serial.print(XY.x_point);
    Serial.print(" Y=");
    Serial.println(XY.y_point);
}

// void On_Swipe_Up()
// {
//     Serial.println("Swipe Up detected");
// }

// void On_Swipe_Down()
// {
//     Serial.println("Swipe Down detected");
// }

// void On_Swipe_Left()
// {
//     Serial.println("Swipe Left detected");
// }

// void On_Swipe_Right()
// {
//     Serial.println("Swipe Right detected");
// }

// void On_Click()
// {
//     Serial.println("Click detected");
// }

// void On_Double_Click()
// {
//     Serial.println("Double Click detected");
// }

// void On_Long_Press()
// {
//     Serial.println("Long Press detected");
// }