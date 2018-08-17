#define HIGH 255
#define ACTIVESTATE 1
#define LOW 0
#include "typedefs.h"
extern u8 i;

      void Game(void){
          u16 x=50;
          u16 y=50;
          u16 y_coor=0;
          u16 x_coor=0;
          u16 circle_color[3]= {CL_BLACK ,CL_GREEN ,CL_RED};
          int counter =0;
          
          TFT_Fill_Screen(CL_WHITE);

          GPIO_Digital_Input(&GPIOD_IDR,_GPIO_PINMASK_4);        //UP
          GPIO_Digital_Input(&GPIOD_IDR,_GPIO_PINMASK_2);      //LEFT
          GPIO_Digital_Input(&GPIOB_IDR,_GPIO_PINMASK_5);      //DOWN
          GPIO_Digital_Input(&GPIOA_IDR,_GPIO_PINMASK_6);     //RIGHT
          GPIO_Digital_Input(&GPIOA_IDR,_GPIO_PINMASK_0);      //Forward
          GPIO_Digital_Input(&GPIOC_IDR,_GPIO_PINMASK_13);      // Backward
          TFT_Set_Pen(CL_BLACK,10);
          TFT_Circle(x,y, 2);
          TFT_Set_Pen(CL_BLACK, 2);
          TFT_Set_Font(TFT_defaultFont, CL_BLACK, FO_HORIZONTAL);
          TFT_H_Line(240, 320, 200);
          TFT_V_Line(200, 240, 240);
          TFT_Write_Text(" << Back ",250, 210);

               while ( ! (x_coor>240 && y_coor > 200) ) {

               if ((Button(&GPIOA_IDR,0,20,1) == HIGH )){

                 counter++;
                 if (counter > 2){ counter =0;}
                 while (Button(&GPIOA_IDR,0,20,1) == HIGH ) {}
                 }
               else if (Button(&GPIOC_IDR,13, 20,LOW) == HIGH ){

                   counter--;
                   if (counter < 0){ counter =2;}
                   while (Button(&GPIOC_IDR,13, 20,LOW) == HIGH ) {}
                 }



               if  (Button(&GPIOD_IDR,4, 1,LOW) == HIGH ){
               TFT_Set_Pen(CL_WHITE,12);
               TFT_Circle(x,y, 2);
               y--;
               }
               else if (Button(&GPIOB_IDR,5, 1,LOW) == HIGH )
               {
               TFT_Set_Pen(CL_WHITE,12);
               TFT_Circle(x,y, 2);
               y++;

               }

               else if (Button(&GPIOD_IDR,2, 1,LOW) == HIGH )
               {
                TFT_Set_Pen(CL_WHITE,12);
               TFT_Circle(x,y, 2);
               x--;

               }
               else if (Button(&GPIOA_IDR,6, 1,LOW) == HIGH )
               {
               TFT_Set_Pen(CL_WHITE,12);
               TFT_Circle(x,y, 2);
               x++;

               }

               TFT_Set_Pen(circle_color[counter],12);
               TFT_Circle(x,y, 2);
               
                if (TP_TFT_Press_Detect()) {

               for (i=0;i<50;i++){

               TP_TFT_Get_Coordinates(&x_coor,&y_coor);
            /* IntToStr(y, y_str);
             IntToStr(x, x_str);
             TFT_Write_Text(x_str,5, 5);
             TFT_Write_Text(y_str,5, 15);    */
               }

               }
           }
            return;
               
       }