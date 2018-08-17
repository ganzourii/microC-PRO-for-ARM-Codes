 #define HIGH 255
 #define ACTIVESTATE 1
 #define LOW 0

 #include <stdlib.h>
 #include "debug.h"
 #include "typedefs.h"
 #include "BitOp.h"
                         /* Touch Program included c files Comm, Paint, Game and typedefs.h*/
void Calibrate(void);
void Game(void);
void Comm(void);
void Paint(void);
unsigned int TFT_DataPort at GPIOE_ODR;
sbit TFT_WR at GPIOE_ODR.B11;
sbit TFT_RD at GPIOE_ODR.B10;
sbit TFT_CS at GPIOE_ODR.B15;
sbit TFT_RS at GPIOE_ODR.B12;
sbit TFT_RST at GPIOE_ODR.B8;
sbit TFT_BLED at GPIOE_ODR.B9;

sbit DriveX_Left at GPIOB_ODR.B1;
sbit DriveX_Right at GPIOB_ODR.B8;
sbit DriveY_Up at GPIOB_ODR.B9;
sbit DriveY_Down at GPIOB_ODR.B0;

u16 x;
u16 y;
u8 i;
u8 RefillFlag =1;
u8 x_str[7];
u8 y_str[7];
int SavedColors[4][2000];
int counter;
char InFlag =0;
void main() {


           ADC_Set_Input_Channel(_ADC_CHANNEL_8 | _ADC_CHANNEL_9 );
           ADC1_Init();


           TFT_Set_Default_Mode();
           TFT_Init_ILI9341_8bit(320,240);

           TP_TFT_Init(320,240,8,9);
           TP_TFT_Set_ADC_Threshold(750);

           TFT_Fill_Screen(CL_BLACK);
           Calibrate();

           TFT_Fill_Screen(CL_WHITE);
           TFT_Set_Pen(CL_BLACK, 2);
           TFT_Set_Font(TFT_defaultFont, CL_BLACK, FO_HORIZONTAL);
           TFT_H_Line(0, 320, 80);
           TFT_H_Line(0, 320, 160);
           TFT_H_Line(0, 320, 240);
           TFT_Write_Text("Game",155, 40);
           TFT_Write_Text("Communication",120, 120);
           TFT_Write_Text("Paint",155, 200);
         
           while (1){
           
           if (RefillFlag == 0) {
           TFT_Fill_Screen(CL_WHITE);
           TFT_Set_Pen(CL_BLACK, 2);
           TFT_Set_Font(TFT_defaultFont, CL_BLACK, FO_HORIZONTAL);
           TFT_H_Line(0, 320, 80);
           TFT_H_Line(0, 320, 160);
           TFT_H_Line(0, 320, 240);
           TFT_Write_Text("Game",155, 40);
           TFT_Write_Text("Communication",120, 120);
           TFT_Write_Text("Paint",155, 200);
           RefillFlag=1;
           }
           
             if (TP_TFT_Press_Detect()) {
             
             for (i=0;i<50;i++){
             
             TP_TFT_Get_Coordinates(&x,&y);
            /* IntToStr(y, y_str);
             IntToStr(x, x_str);
             TFT_Write_Text(x_str,5, 5);
             TFT_Write_Text(y_str,5, 15);    */
             }
             
             if ( y < 80 ) 
             {

             Game();
             RefillFlag =0;
             }
             else if (y > 80 && y < 160)
             {
             Comm();
             RefillFlag=0;
             }
             else if (y > 160)
             {
             Paint();
             RefillFlag=0;
             }
           }



}

}














void Calibrate(void) {
  TFT_Set_Pen(CL_WHITE, 3);
  TFT_Set_Font(TFT_defaultFont, CL_WHITE, FO_HORIZONTAL);
  TFT_Write_Text("Touch selected corners for calibration", 50, 80);
  TFT_Line(315, 239, 319, 239);
  TFT_Line(309, 229, 319, 239);
  TFT_Line(319, 234, 319, 239);
  TFT_Write_Text("first here",235,220);

  TP_TFT_Calibrate_Min();                      // Calibration of bottom left corner
  Delay_ms(500);
        TFT_Set_Pen(CL_BLACK, 3);
  TFT_Set_Font(TFT_defaultFont, CL_BLACK, FO_HORIZONTAL);
  TFT_Line(315, 239, 319, 239);
  TFT_Line(309, 229, 319, 239);
  TFT_Line(319, 234, 319, 239);
  TFT_Write_Text("first here",235,220);

  TFT_Set_Pen(CL_WHITE, 3);
  TFT_Set_Font(TFT_defaultFont, CL_WHITE, FO_HORIZONTAL);
  TFT_Write_Text("now here ", 20, 5);
  TFT_Line(0, 0, 5, 0);
  TFT_Line(0, 0, 0, 5);
  TFT_Line(0, 0, 10, 10);

  TP_TFT_Calibrate_Max();                      // Calibration of bottom left corner
  Delay_ms(500);
}