#include <main.h>


UBYTE flag = 0,flgh = 0;
UWORD x,y,l = 0;

void Touch_INT_callback()
{
    flag = TOUCH_IRQ;
}

void setup()
{  
    Serial.begin(115200);
    while (!Serial) {
        delay(10);
    }
    delay(10000);
    Serial.println("test");
    Serial.println("1");
    Touch_1IN28_XY XY;
        Serial.println("2");

    XY.mode = 0;
    XY.x_point = 0;
        Serial.println("3");

    XY.y_point = 0;
    Config_Init();
        Serial.println("4");

    LCD_Init();
    Serial.println("4.25");
    if(Touch_1IN28_init(XY.mode) == true)
        Serial.println("OK!");
    else {
            Serial.println("4.5");
                    Serial.println("NO!");


    }

    Serial.println("5");


    // LCD_SetBacklight(1000);
    //     Serial.println("6");

    Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 0, BLACK);
        Serial.println("7");

    Paint_Clear(WHITE);
        Serial.println("8");

    pinMode(TP_INT_PIN, INPUT_PULLUP);  // Configure pin first
attachInterrupt(digitalPinToInterrupt(TP_INT_PIN), Touch_INT_callback, FALLING);    Serial.println("10");

    Paint_DrawString_EN(35, 90, "Gesture test", &Font20, BLACK, WHITE);    Serial.println("11");

    Paint_DrawString_EN(10, 120, "Complete as prompted", &Font16, BLACK, WHITE);    Serial.println("12");

    // DEV_Delay_ms(500);
            Serial.println("13");


                if(Touch_1IN28_init(XY.mode) == true)
        Serial.println("OK!");
    else {
            Serial.println("gigle2");
                    Serial.println("NO!");


    }
}

void loop()
{   
    Serial.println("direl");
           Paint_ClearWindows(10,90,230,137,WHITE);  
        Serial.println("direl1");
    Paint_DrawString_EN(105, 100, "Up", &Font24, 0X647C, WHITE);
        Serial.println("direl3");

    while(XY.Gesture != UP)
    {    

        if (flag == TOUCH_IRQ)
        {
                    Serial.println("direl69");

            XY.Gesture = DEV_I2C_Read_Byte(address,0x01);
            flag = TOUCH_DRAW;
        }      
            Serial.println("direl7");

        DEV_Delay_ms(10);   
    }
        Serial.println("direl8");


    Paint_ClearWindows(105,100,160,155,WHITE);  
        Serial.println("direl9");

    Paint_DrawString_EN(85, 100, "Down", &Font24, 0X647C, WHITE);
        Serial.println("direl10");

    while(XY.Gesture != Down)
    {
            Serial.println("direl11");

        if (flag == TOUCH_IRQ)
        {
                Serial.println("direl12");

            XY.Gesture = DEV_I2C_Read_Byte(address,0x01);
                Serial.println("direl13");

            flag = TOUCH_DRAW;
        }    
            Serial.println("direl14");

        DEV_Delay_ms(10);     
    }

        Serial.println("direl15");


    Paint_ClearWindows(85, 100,160,155,WHITE);
        Serial.println("direl16");

    Paint_DrawString_EN(85, 100, "Left", &Font24, 0X647C, WHITE);
        Serial.println("direl17");

    while(XY.Gesture != LEFT)
    {
            Serial.println("direl18");

        if (flag == TOUCH_IRQ)
        {
            XY.Gesture = DEV_I2C_Read_Byte(address,0x01);
                Serial.println("direl19");

            flag = TOUCH_DRAW;
                Serial.println("direl20");

        }    
        DEV_Delay_ms(10);  
            Serial.println("direl21");
   
    }

    Paint_ClearWindows(85, 100,160,155,WHITE);
        Serial.println("direl22");

    Paint_DrawString_EN(80, 100, "Right", &Font24, 0X647C, WHITE);
        Serial.println("direl23");

    while(XY.Gesture != RIGHT)
    {
            Serial.println("direl24");

        if (flag == TOUCH_IRQ)
        {
                Serial.println("direl25");

            XY.Gesture = DEV_I2C_Read_Byte(address,0x01);
                Serial.println("direl26");

            flag = TOUCH_DRAW;
        }     
            Serial.println("direl27");

        DEV_Delay_ms(10);    
    }

        Serial.println("direl28");

    Paint_ClearWindows(80, 100,165,160,WHITE);
        Serial.println("direl29");

    Paint_DrawString_EN(47, 100, "Long Press", &Font20, 0X647C, WHITE);
    while(XY.Gesture != LONG_PRESS)
    {
            Serial.println("direl30");

        if (flag == TOUCH_IRQ)
        {
            XY.Gesture = DEV_I2C_Read_Byte(address,0x01);
            flag = TOUCH_DRAW;
                Serial.println("direl31");

        }     
        DEV_Delay_ms(10);    
    }

        Serial.println("direl32");


    Paint_ClearWindows(47, 100,200,155,WHITE);
        Serial.println("direl33");

    Paint_DrawString_EN(35, 100, "Double Click", &Font20, 0X647C, WHITE);
        Serial.println("direl34");

    while(XY.Gesture != DOUBLE_CLICK)
    {
            Serial.println("direl34");

        if (flag == TOUCH_IRQ)
        {
                Serial.println("direl35");

            XY.Gesture = DEV_I2C_Read_Byte(address,0x01);
            flag = TOUCH_DRAW;
        } 
        DEV_Delay_ms(10);        
    }

        Serial.println("direl36");


    XY.mode = 1;
        Serial.println("direl37");

    Touch_1IN28_init(XY.mode);
        Serial.println("direl38");

    Paint_ClearWindows(10,90,230,137,WHITE);  
    Paint_DrawRectangle(0, 0, 35, 208,RED,DOT_PIXEL_1X1,DRAW_FILL_FULL);
    Paint_DrawRectangle(0, 0, 208, 35,GREEN,DOT_PIXEL_1X1,DRAW_FILL_FULL);
    Paint_DrawRectangle(206, 0, 240, 240,BLUE,DOT_PIXEL_1X1,DRAW_FILL_FULL);
    Paint_DrawRectangle(0, 206, 240, 240,GRAY,DOT_PIXEL_1X1,DRAW_FILL_FULL);
        Serial.println("direl39");

    while (1)
    {
        if (flag == TOUCH_IRQ)
        {
            XY = Touch_1IN28_Get_Point();
            if(flgh == TOUCH_INIT && XY.x_point != TOUCH_INIT)
            {
                flgh = 1; 
                //Get the coordinates of the first point    获取第一次点的坐标
                x = XY.x_point;
                y = XY.y_point;
            }
            if ((XY.x_point > 35 && XY.x_point < 205) && (XY.y_point > 35 && XY.y_point < 208))
            {
                flgh = TOUCH_DRAW; // Permit painting     允许画
            }
            else
            {
                if ((XY.x_point > 0 && XY.x_point < 33) && (XY.y_point > 0 && XY.y_point < 208)){
                    XY.color = RED;
                }
                if ((XY.x_point > 0 && XY.x_point < 208) && (XY.y_point > 0 && XY.y_point < 33)){
                    XY.color = GREEN;
                }
                if ((XY.x_point > 208 && XY.x_point < 240) && (XY.y_point > 0 && XY.y_point < 240)){
                    XY.color = BLUE;
                }
                if ((XY.x_point > 0 && XY.x_point < 240) && (XY.y_point > 208 && XY.y_point < 240)){
                    Paint_ClearWindows(35,35,205,205,WHITE);
                }

                flgh = TOUCH_NO_DRAW; //No painting     禁止画
                flag = TOUCH_DRAW; //Change interrupt bit      改变中断位
            }

            if (flgh == TOUCH_DRAW)
            {
                XY.x_point = (XY.x_point > 37)? XY.x_point : 37;
                XY.y_point = (XY.y_point > 37)? XY.y_point : 37;

                XY.x_point = (XY.x_point < 205)? XY.x_point : 205;
                XY.y_point = (XY.y_point < 203)? XY.y_point : 203; 
                
                if (l<10350) //Continuous drawing    连续画
                {
                    flag = TOUCH_DRAW;
                    Paint_DrawLine(x,y,XY.x_point, XY.y_point, XY.color, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
                    l=0;
                }
                else//Draw Point    画点
                {
                    flag = TOUCH_DRAW; 
                    Paint_DrawPoint(XY.x_point, XY.y_point, XY.color, DOT_PIXEL_2X2, DOT_FILL_AROUND);
                    l = 0; 
                }
                x = XY.x_point;
                y = XY.y_point;
            }
        }
        l++;
        if (l>10600) //Decide whether to draw dots or lines   判断画点还是画线
        {
            l=10500;
        }
    }
    
    
    
}

// /*********************************************************************************************************
//   END FILE
// *********************************************************************************************************/