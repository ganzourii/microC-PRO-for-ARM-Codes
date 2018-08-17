 #define HIGH 255
 #include <stdlib.h>
 #include "debug.h"
 #include "typedefs.h"
 #include "BitOp.h"


void main(void) {


                int i;
                GPIO_Digital_Output(&GPIOA_ODR,_GPIO_PINMASK_4);
                GPIO_Digital_Output(&GPIOA_ODR,_GPIO_PINMASK_5);
                DAC1_Init(_DAC_CH2_ENABLE);
                
              while (1) {

              
            for (i = 1000;i<4000;i++){
              DAC1_Ch2_Output(i);
               Delay_ms(2);
              }
              

              
              }





}