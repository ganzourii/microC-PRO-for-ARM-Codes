#define HIGH 255
#define ACTIVESTATE 1
#define LOW 0
#include "typedefs.h"
extern u8 i;

void Comm(void) {

u16 Sequence[50]={0};
u8 counter =0;
u8 LimitationFlag =1;
u16 thesequence;
char seq_str[51];
u16 y_coor=0;
u16 x_coor=0;

          TFT_Fill_Screen(CL_WHITE);

          GPIO_Digital_Input(&GPIOD_IDR,_GPIO_PINMASK_4);     //Nummber 0
          GPIO_Digital_Input(&GPIOD_IDR,_GPIO_PINMASK_2);     //Number 3
          GPIO_Digital_Input(&GPIOA_IDR,_GPIO_PINMASK_6);     //Number 2
          GPIO_Digital_Input(&GPIOB_IDR,_GPIO_PINMASK_5);     //Number 1
          GPIO_Digital_Input(&GPIOC_IDR,_GPIO_PINMASK_13);     //Start sequence
          GPIO_Digital_Input(&GPIOC_IDR,_GPIO_PINMASK_0);     //Send Sequence
          
          
          TFT_Set_Pen(CL_BLACK, 2);
          TFT_Set_Font(TFT_defaultFont, CL_BLACK, FO_HORIZONTAL);
          TFT_H_Line(240, 320, 200);
          TFT_V_Line(200, 240, 240);
          TFT_Write_Text(" << Back ",250, 210);

           while ( ! (x_coor>240 && y_coor > 200) ) 
           {

              if ( Button(&GPIOC_IDR,13,20,LOW) == HIGH ) {
              TFT_Fill_Screen(CL_WHITE);
              TFT_Write_Text("Enter the Sequence",100, 110);
              counter = 0;
              LimitationFlag =0;

              while (Button(&GPIOC_IDR,13,20,LOW) == HIGH ) {}
              }
              
               if (LimitationFlag == 0) {

                if (Button(&GPIOD_IDR,4,20,LOW) == HIGH ){
                TFT_Fill_Screen(CL_BLACK);
                      Sequence[counter] = 0;
                      counter ++;
                      while (Button(&GPIOD_IDR,4,20,LOW) == HIGH ) {}
                      }
                else if (Button(&GPIOB_IDR,5,20,LOW) == HIGH ){
                TFT_Fill_Screen(CL_WHITE);
                      Sequence[counter] = 1;
                      counter ++;
                      while (Button(&GPIOB_IDR,5,20,LOW) == HIGH ) {}
                      }
                else if (Button(&GPIOA_IDR,6,20,LOW) == HIGH ){
                      Sequence[counter] = 2;
                      counter ++;
                      while (Button(&GPIOA_IDR,6,20,LOW) == HIGH ) {}
                      }
                else if (Button(&GPIOD_IDR,2,20,LOW) == HIGH ){
                      Sequence[counter] = 3;
                      counter ++;
                      while (Button(&GPIOD_IDR,2,20,LOW) == HIGH ) {}
                      }
               }
               
               if (counter ==50) { LimitationFlag =1; }


                if ( Button(&GPIOC_IDR,0,20,1) == HIGH) {
                TFT_Fill_Screen(CL_WHITE);
                TFT_H_Line(240, 320, 200);
                TFT_V_Line(200, 240, 240);
                TFT_Write_Text(" << Back ",250, 210);
                
                for(i =0;i<counter;i++){
                thesequence = Sequence[i];
                IntToStr(thesequence,seq_str);
                TFT_Write_Text(seq_str,(120+i*10),100);
                }

                 while ( Button(&GPIOC_IDR,0,20,1) == HIGH) {}
                }
               
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