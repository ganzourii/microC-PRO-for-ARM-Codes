 #define HIGH 255
 #define LOW 0
 #include <stdlib.h>
 #include "debug.h"
 #include "typedefs.h"
 #include "BitOp.h"


    unsigned int TFT_DataPort at GPIOE_ODR;
              sbit TFT_RST at GPIOE_ODR.B8;
              sbit TFT_RS at GPIOE_ODR.B12;
              sbit TFT_CS at GPIOE_ODR.B15;
              sbit TFT_RD at GPIOE_ODR.B10;
              sbit TFT_WR at GPIOE_ODR.B11;
              
void main() {
          u16 x=50;
          u16 y=50;
          u16 circle_color[3]= {CL_BLACK ,CL_GREEN ,CL_RED};
          u8 counter =0;
          TFT_Set_Default_Mode();
          TFT_Init_ILI9341_8bit(320,240);

          TFT_Fill_Screen(CL_AQUA);

          GPIO_Digital_Input(&GPIOD_IDR,_GPIO_PINMASK_4);        //UP
          GPIO_Digital_Input(&GPIOD_IDR,_GPIO_PINMASK_2);      //LEFT
          GPIO_Digital_Input(&GPIOB_IDR,_GPIO_PINMASK_5);      //DOWN
          GPIO_Digital_Input(&GPIOA_IDR,_GPIO_PINMASK_6);     //RIGHT
          GPIO_Digital_Input(&GPIOA_IDR,_GPIO_PINMASK_9);      //Forward
          GPIO_Digital_Input(&GPIOC_IDR,_GPIO_PINMASK_4);      // Backward
          TFT_Set_Pen(CL_BLACK,10);
          TFT_Circle(x,y, 2);

          while (1) {
          
           if  ((Button(&GPIOA_IDR,9,20,1) == HIGH )){
             TFT_Fill_Screen(CL_AQUA);
              counter++;
              if (counter > 2){ counter =0;}
           }


            if  (Button(&GPIOD_IDR,4, 1,LOW) == HIGH ){
            TFT_Set_Pen(CL_AQUA,10);
               TFT_Circle(x,y, 2);
            y--;
            }
               else if (Button(&GPIOB_IDR,5, 1,LOW) == HIGH )
               {
                 TFT_Set_Pen(CL_AQUA,10);
               TFT_Circle(x,y, 2);
               y++;

               }
            
               else if (Button(&GPIOD_IDR,2, 1,LOW) == HIGH )
               {
                TFT_Set_Pen(CL_AQUA,10);
               TFT_Circle(x,y, 2);
               x--;

               }
               else if (Button(&GPIOA_IDR,6, 1,LOW) == HIGH )
               {
               TFT_Set_Pen(CL_AQUA,10);
               TFT_Circle(x,y, 2);
               x++;

               }

               TFT_Set_Pen(circle_color[counter],10);
               TFT_Circle(x,y, 2);
               
               }
               

         }
