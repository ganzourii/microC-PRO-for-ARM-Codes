#include <stdlib.h>
        #define ACTIVEstatus 1
         void ToggleLed (char PortName, char PinNum);


void main() {


     GPIO_Digital_Output(&GPIOD_ODR,_GPIO_PINMASK_ALL);
          // CHAR BUTTON
     GPIO_Digital_Input(&GPIOB_IDR,_GPIO_PINMASK_3);        // INT BUTTON
     GPIO_Digital_Input(&GPIOB_IDR,_GPIO_PINMASK_2);        //DOUBLE/FLOAT BUTTON
     GPIO_Digital_Input(&GPIOB_IDR,_GPIO_PINMASK_1);        // LONG DOUBLE BUTTON
     GPIO_Digital_Input(&GPIOB_IDR,_GPIO_PINMASK_0);
     GPIOD_ODR =0;

               while (1) {
               
                    if ( Button(&GPIOB_IDR,2,1,ACTIVEstatus) == 255) {
                    
                        GPIOD_ODR =sizeof(int);

                        }
                        

               }

}


