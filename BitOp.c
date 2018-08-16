void setbit (char PortName, char PinNum ){


       switch(PortName){

       case 'A' :
              GPIO_Digital_Output(&GPIOA_ODR,_GPIO_PINMASK_ALL);
                    GPIOA_ODR |= (1 << PinNum)  ;
              break;
       case 'B' :
              GPIO_Digital_Output(&GPIOB_ODR,_GPIO_PINMASK_ALL);
                    GPIOB_ODR |= (1 << PinNum)  ;

              break;
       case 'D' :
              GPIO_Digital_Output(&GPIOD_ODR,_GPIO_PINMASK_ALL);
                    GPIOD_ODR |= (1 << PinNum)  ;
                    
               break;

     }
     }
void setHALFPORT (char PortName, char Level )  {

            switch(PortName){

       case 'A' :
                GPIO_Digital_Output(&GPIOA_ODR,_GPIO_PINMASK_ALL);
                if ( Level == 'H'){
                    GPIOA_ODR |= 0xFF00  ;
                    }
                else if( Level == 'L'){
                    GPIOA_ODR |= 0x00FF ;
                    }
              break;
       case 'B' :
              GPIO_Digital_Output(&GPIOB_ODR,_GPIO_PINMASK_ALL);
                    if ( Level == 'H'){
                    GPIOB_ODR |= 0xFF00  ;
                    }
                else if( Level == 'L'){
                    GPIOB_ODR |= 0x00FF ;
                    }

              break;
       case 'D' :
                    GPIO_Digital_Output(&GPIOD_ODR,_GPIO_PINMASK_ALL);
                    if ( Level == 'H'){
                    GPIOD_ODR |= 0xFF00  ;
                    }
                    else if( Level == 'L'){
                    GPIOD_ODR |= 0x00FF ;
                    }

               break;

     }
     }
void clearHALFPORT (char PortName, char Level ) {

            switch(PortName){

       case 'A' :
                GPIO_Digital_Output(&GPIOA_ODR,_GPIO_PINMASK_ALL);
                if ( Level == 'H'){
                    GPIOA_ODR &= ~(0xFF00)  ;
                    }
                else if( Level == 'L'){
                    GPIOA_ODR &= ~(0x00FF) ;
                    }
              break;
       case 'B' :
              GPIO_Digital_Output(&GPIOB_ODR,_GPIO_PINMASK_ALL);
                    if ( Level == 'H'){
                    GPIOB_ODR &= ~(0xFF00) ;
                    }
                else if( Level == 'L'){
                    GPIOB_ODR &= ~(0x00FF) ;
                    }

              break;
       case 'D' :
                    GPIO_Digital_Output(&GPIOD_ODR,_GPIO_PINMASK_ALL);
                    if ( Level == 'H'){
                    GPIOD_ODR &= ~(0xFF00)  ;
                    }
                    else if( Level == 'L'){
                    GPIOD_ODR &= ~(0x00FF) ;
                    }

               break;

     }
             }
void clearbit (char PortName, char PinNum ){


       switch(PortName){

       case 'A' :
              GPIO_Digital_Output(&GPIOA_ODR,_GPIO_PINMASK_ALL);
                    GPIOA_ODR &= ~(1 << PinNum)  ;
              break;
       case 'B' :
              GPIO_Digital_Output(&GPIOB_ODR,_GPIO_PINMASK_ALL);
                    GPIOB_ODR &= ~(1 << PinNum)   ;

              break;
       case 'D' :
              GPIO_Digital_Output(&GPIOD_ODR,_GPIO_PINMASK_ALL);
                    GPIOD_ODR &= ~(1 << PinNum)   ;

               break;

     }

}





