 #define HIGH 255
 #include <stdlib.h>
 #include "debug.h"
 #include "typedefs.h"
 #include "BitOp.h"
 
 void Buzzer(unsigned int Frequency,float dutycycle);
 
 void main () {
               u16 value = 0; 
               u8 vol;      // the analog value
               GPIO_Digital_Output(&GPIOD_ODR,_GPIO_PINMASK_ALL);
               GPIO_Digital_Output(&GPIOC_ODR,_GPIO_PINMASK_ALL);
               GPIO_Digital_Output(&GPIOB_ODR,_GPIO_PINMASK_ALL);
               GPIO_Digital_Output(&GPIOA_ODR,_GPIO_PINMASK_ALL);   // present PORTD as Output port
               GPIO_Digital_Input(&GPIOA_IDR,_GPIO_PINMASK_3);         // PA3 as input pin
               ADC_Set_Input_Channel(_ADC_CHANNEL_3);                  // set channel 3 an input channel for ADC
               
               ADC1_Init();                                           //Initialize ADC
      while (1){

              value =  ADC1_Get_Sample(3);
               if (value > 0 && value <1000) {
                  GPIOD_ODR = 0x0001;
               
               
               }
               else if (value > 1000&& value < 2000)
              {


                 GPIOD_ODR = 0x0031;

              }
                 else if (value > 2000&& value < 3000)
              {


                 GPIOD_ODR = 0x0731;

              }
                else if (value > 3000)
              {


                 GPIOD_ODR = 0xF731;

              }
              else
              {
              GPIOD_ODR=0;
              }
              vol = (value/4065);
              Buzzer(1000,vol);
              
                                           // getting the analog value from pot connects to channel 3
           /*   if (value > 0 && value < 300)
              {
                 GPIOC_ODR =0;
                 GPIOB_ODR =0;
                 GPIOA_ODR =0;

                 GPIOD_ODR = 0x0008;
              
              } 
              else if (value > 300 && value < 600)
              {
                 GPIOC_ODR =0;
                 GPIOB_ODR =0;
                 GPIOA_ODR =0;

                 GPIOD_ODR = 0x0088;
                
              }
               else if (value > 600 && value < 900)
              {
                 GPIOC_ODR =0;
                 GPIOB_ODR =0;
                 GPIOA_ODR =0;

                 GPIOD_ODR = 0x0888;
              }
               else if (value > 900 && value < 1200)
              {
                 GPIOC_ODR =0;
                 GPIOB_ODR =0;
                 GPIOA_ODR =0;

                 GPIOD_ODR = 0x8888;
              }
              else if (value > 1200 && value < 1500)
              {

                 GPIOB_ODR =0;
                 GPIOA_ODR =0;
                 GPIOD_ODR = 0x8888;
                 GPIOC_ODR = 0x0008;
              }
              else if (value > 1500 && value < 1800)
              {

                 GPIOB_ODR =0;
                 GPIOA_ODR =0;
                 GPIOD_ODR = 0x8888;
                 GPIOC_ODR = 0x0088;
              }
              else if (value > 1800 && value < 2100)
              {

                 GPIOB_ODR =0;
                 GPIOA_ODR =0;
                 GPIOD_ODR = 0x8888;
                 GPIOC_ODR = 0x0888;
              }
                else if (value > 2100 && value < 2400)
              {


                 GPIOA_ODR =0;
                 GPIOD_ODR = 0x8888;
                 GPIOC_ODR = 0x0888;
                 GPIOB_ODR = 0x0008;
              }
                else if (value > 2400 && value < 2700)
              {


                 GPIOA_ODR =0;
                 GPIOD_ODR = 0x8888;
                 GPIOC_ODR = 0x0888;
                 GPIOB_ODR = 0x0088;
              }
               else if (value > 2700 && value < 3000)
              {


                 GPIOA_ODR =0;
                 GPIOD_ODR = 0x8888;
                 GPIOC_ODR = 0x0888;
                 GPIOB_ODR = 0x0888;
              }
               else if (value > 3000 && value < 3300)
              {

                 GPIOD_ODR = 0x8888;
                 GPIOC_ODR = 0x0888;
                 GPIOB_ODR = 0x0888;
                 GPIOA_ODR = 0x0008;
              }
               else if (value > 3000 && value < 3300)
              {

                 GPIOD_ODR = 0x8888;
                 GPIOC_ODR = 0x0888;
                 GPIOB_ODR = 0x0888;
                 GPIOA_ODR = 0x0088;
              }
              else if (value > 3300 && value < 3600)
              {

                 GPIOD_ODR = 0x8888;
                 GPIOC_ODR = 0x0888;
                 GPIOB_ODR = 0x0888;
                 GPIOA_ODR = 0x0888;
              }
              else if (value > 3600 && value < 3900)
              {

                 GPIOD_ODR = 0x8888;
                 GPIOC_ODR = 0x0888;
                 GPIOB_ODR = 0x0888;
                 GPIOA_ODR = 0x8888;
              }                   */

                }
 
 }