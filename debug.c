void TogglePORT (char PortName){

       switch(PortName){

       case 'A' :
              GPIO_Digital_Output(&GPIOA_ODR,_GPIO_PINMASK_ALL);
                    GPIOA_ODR = 0xFFFF ;
                    Delay_ms(500);
                    GPIOA_ODR =0;
                    Delay_ms(500);

              break;
       case 'B' :
              GPIO_Digital_Output(&GPIOB_ODR,_GPIO_PINMASK_ALL);
                    GPIOB_ODR = 0xFFFF  ;
                    Delay_ms(500);
                    GPIOB_ODR =0;
                    Delay_ms(500);

              break;
       case 'D' :
              GPIO_Digital_Output(&GPIOD_ODR,_GPIO_PINMASK_ALL);
                    GPIOD_ODR = 0xFFFF  ;
                    Delay_ms(500);
                    GPIOD_ODR =0;
                    Delay_ms(500);
               break;





     }








}
void ToggleLED (char PortName, char PinNum) {

       switch(PortName){

       case 'A' :
              GPIO_Digital_Output(&GPIOA_ODR,_GPIO_PINMASK_ALL);
                    GPIOA_ODR = 1 << PinNum  ;
                    Delay_ms(500);
                    GPIOA_ODR =0;
                    Delay_ms(500);

              break;
       case 'B' :
              GPIO_Digital_Output(&GPIOB_ODR,_GPIO_PINMASK_ALL);
                    GPIOB_ODR = 1 << PinNum  ;
                    Delay_ms(500);
                    GPIOB_ODR =0;
                    Delay_ms(500);

              break;
       case 'D' :
              GPIO_Digital_Output(&GPIOD_ODR,_GPIO_PINMASK_ALL);
                    GPIOD_ODR = 1 << PinNum  ;
                    Delay_ms(500);
                    GPIOD_ODR =0;
                    Delay_ms(500);
               break;





     }
}