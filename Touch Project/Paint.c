#define HIGH 255
#define ACTIVESTATE 1
#define LOW 0
#include "typedefs.h"

extern u16 x;
extern u16 y;
extern SavedColors[4][10000];
extern int counter;
extern char InFlag;
void Paint(void)
{   int i;
    u8 size = 3;
    u16 color = CL_BLACK;

    TFT_Fill_Screen(CL_WHITE);
    TFT_Set_Pen(CL_BLACK, 2);
    TFT_Set_Font(TFT_defaultFont, CL_BLACK, FO_HORIZONTAL);
    
  if ( InFlag == 1) {
    TFT_H_Line(0, 320, 120);
    TFT_Write_Text("Countine?", 140, 70);
    TFT_Write_Text("New Artwork", 140, 180);
                                             /*New edit for saving the last artwork in Paint */

    while(!(TP_TFT_Press_Detect()) ) {}
      for (i=0;i<50;i++){

             TP_TFT_Get_Coordinates(&x,&y);
            /* IntToStr(y, y_str);
             IntToStr(x, x_str);
             TFT_Write_Text(x_str,5, 5);
             TFT_Write_Text(y_str,5, 15);    */
             }

        if ( y > 120 ) {

        TFT_Fill_Screen(CL_WHITE);
        TFT_Set_Pen(CL_BLACK, 2);
        TFT_Set_Font(TFT_defaultFont, CL_BLACK, FO_HORIZONTAL);
        counter =0;
        
        }
        else if ( y < 120  ){
        i=0;
        TFT_Fill_Screen(CL_WHITE);
        TFT_Set_Pen(CL_BLACK, 2);
        TFT_Set_Font(TFT_defaultFont, CL_BLACK, FO_HORIZONTAL);
        
        while(i<counter){

        x = SavedColors[0][i];
        y = SavedColors[1][i];
        color = SavedColors[2][i];
        size = SavedColors[3][i];

        TFT_Set_Pen(color, size);
        TFT_Circle(x, y, 1);

        i++;
        }
        TFT_Set_Pen(CL_BLACK, 2);
        TFT_Set_Font(TFT_defaultFont, CL_BLACK, FO_HORIZONTAL);
        }
      }
                                                      /******************/
    TFT_H_Line(0, 320, 30);
    TFT_Write_Text(" << Back", 9, 5);
    TFT_V_Line(0, 30, 80);
    TFT_V_Line(0, 30, 160);
    TFT_V_Line(0, 30, 240);

    //ERASE
    TFT_Rectangle(0, 190, 50, 240);

    //SIZES
    TFT_Rectangle(0, 30, 40, 60);
    TFT_Write_Text("3", 14, 40);
    TFT_Rectangle(0, 60, 40,90);
    TFT_Write_Text("7", 14, 65);
    TFT_Rectangle(0, 90, 40, 120);
    TFT_Write_Text("10", 12, 95);


    TFT_Set_Pen(CL_BLACK, 7);
    TFT_Circle(120, 12, 3);

    TFT_Set_Pen(CL_RED, 7);
    TFT_Circle(190, 12, 3);

    TFT_Set_Pen(CL_BLUE, 7);
    TFT_Circle(280, 12, 3);

    TFT_Set_Pen(CL_BLACK, 3);

    while(1)
    {
        while (!TP_TFT_Press_Detect());

        TP_TFT_Get_Coordinates(&x, &y);

        if (x > 80 && x < 160 && y <= 30)
        {
             color = CL_BLACK;
             TFT_Set_Pen(color, size);
             continue;
        }

        else if (x >160 && x < 240 && y <30)
        {
             color = CL_RED;
             TFT_Set_Pen(color, size);
             continue;
        }

        else if (x >240 && x <320 && y <30)
        {
             color = CL_BLUE;
             TFT_Set_Pen(color, size);
             continue;
        }

        /*********/

        else if (x <= 25 && y >= 25 && y < 50)
        {
             size = 3;
             TFT_Set_Pen(color, size);
             continue;
        }

        else if (x <= 25 && y >= 50 && y < 75)
        {
             size = 7;
             TFT_Set_Pen(color, size);
             continue;
        }

        else if (x <= 25 && y >= 75 && y <= 100)
        {
             size = 10;
             TFT_Set_Pen(color, size);
             continue;
        }

        else if (x < 50 && y > 190 && y < 240)
        {
             color = CL_WHITE;
             size = 12;
             TFT_Set_Pen(color, size);
             continue;
        }

        TFT_Circle(x, y, 1);
        
        if (x < 80 && y < 30)
        {

             break;
        }
        if ( counter == 8000) {
           TFT_Set_Font(TFT_defaultFont, CL_WHITE, FO_HORIZONTAL);
           TFT_Write_Text("FULL!!!!",150, 110);
           TFT_Set_Font(TFT_defaultFont, CL_BLACK, FO_HORIZONTAL);
        }
        else {
        SavedColors[0][counter] = x;
        SavedColors[1][counter] = y;
        SavedColors[2][counter] = color;
        SavedColors[3][counter] = size;
        counter ++;
       }
    }
    InFlag = 1;
}