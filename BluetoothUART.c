#define HIGH 255
#define ACTIVESTATE 1
#define LOW 0
#include <stdlib.h>
#include "debug.h"
#include "typedefs.h"
#include "BitOp.h"
                         /* Touch Program included c files Comm, Paint, Game and typedefs.h*/

unsigned int TFT_DataPort at GPIOE_ODR;
sbit TFT_WR at GPIOE_ODR.B11;
sbit TFT_RD at GPIOE_ODR.B10;
sbit TFT_CS at GPIOE_ODR.B15;
sbit TFT_RS at GPIOE_ODR.B12;
sbit TFT_RST at GPIOE_ODR.B8;
sbit TFT_BLED at GPIOE_ODR.B9;

void  BT_Configure();


  char recievedDATA;

  void main() {
         int i;

           TFT_Set_Default_Mode();
           TFT_Init_ILI9341_8bit(320,240);
           TFT_Fill_Screen(CL_WHITE);
           TFT_Set_Font(TFT_defaultFont, CL_BLACK, FO_HORIZONTAL);

UART3_Init_Advanced(115200, _UART_8_BIT_DATA, _UART_NOPARITY, _UART_ONE_STOPBIT, &_GPIO_MODULE_USART3_PD89);
Delay_ms(100);                // UART3 Init

    // Configure BlueTooth-Click module
BT_Configure();



Delay_ms(4000);



  i=0   ;
while (1) {
   if (   UART3_Data_Ready() ){
   recievedDATA = UART3_Read();
   TFT_Write_Char(recievedDATA,(150+i*10),120);
   i++;}
}
	 
	 
	 
}








void  BT_Configure() {

    UART3_Write_Text("$$$");                  // Enter command mode
    Delay_ms(500);
	Delay_ms(500);

    UART3_Write_Text("SN,BlueTooth-Click");   // Name of device
    UART3_Write(13);                          // CR
    Delay_ms(500);
	Delay_ms(500);

    UART3_Write_Text("SO,Slave");             // Extended status string
    UART3_Write(13);                          // CR
    Delay_ms(500);
	Delay_ms(500);

    UART3_Write_Text("SM,0");                 // Set mode (0 = slave, 1 = master, 2 = trigger, 3 = auto, 4 = DTR, 5 = ANY)
    UART3_Write(13);                          // CR
    Delay_ms(500);
	Delay_ms(500);

    UART3_Write_Text("SA,1");                 // Authentication (1 to enable, 0 to disable)
    UART3_Write(13);                          // CR
    Delay_ms(500);
	Delay_ms(500);


    UART3_Write_Text("SP,1234");              // Security pin code (mikroe)
    UART3_Write(13);                          // CR
    Delay_ms(500);
	Delay_ms(500);


    UART3_Write_Text("---");                  // Security pin code (mikroe)
    UART3_Write(13);                          // CR
    Delay_ms(500);
	Delay_ms(500);
}

