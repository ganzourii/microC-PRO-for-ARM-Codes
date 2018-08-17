  #define UpPin 4
  #define DownPin 5
  #define RightPin 6
  #define LeftPin 2
  #define HIGH 255
  #define LOW 0
  #define ACTIVEstatus 1



void main() {
       char flagPORTD =0;
       char flagPORTC =0;
       char flagPORTB =0;
       
       GPIO_Digital_Output(&GPIOD_ODR,_GPIO_PINMASK_ALL);
       GPIO_Digital_Output(&GPIOC_ODR,_GPIO_PINMASK_ALL);
       GPIO_Digital_Output(&GPIOB_ODR,_GPIO_PINMASK_ALL);
       GPIO_Digital_Input(&GPIOD_IDR,_GPIO_PINMASK_4);       //Up
       GPIO_Digital_Input(&GPIOD_IDR,_GPIO_PINMASK_2);        //left
       GPIO_Digital_Input(&GPIOB_IDR,_GPIO_PINMASK_5);         //Down
       GPIO_Digital_Input(&GPIOA_IDR,_GPIO_PINMASK_6);     // RIGHT
       
       GPIOC_ODR= 0;
       GPIOB_ODR= 0x0100;
       GPIOD_ODR= 0;
       
             while (1){
       
                     while( Button(&GPIOD_IDR,UpPin,1,ACTIVEstatus) == LOW){
                     
                             if( GPIOD_ODR != 0){
                             
                                if (flagPORTD == 0 ){
                                    flagPORTD =1;
                                 if (GPIOD_ODR == 0x0008){  GPIOD_ODR ^= 0x0008 ; Delay_ms(100); GPIOD_ODR ^= 0x0008;      Delay_ms(100); GPIOD_ODR ^= 0x0008; Delay_ms(100); GPIOD_ODR ^= 0x0008;}
                                 else if (GPIOD_ODR == 0x0080){  GPIOD_ODR ^= 0x0080 ; Delay_ms(100); GPIOD_ODR ^= 0x0080; Delay_ms(100); GPIOD_ODR ^= 0x0080; Delay_ms(100); GPIOD_ODR ^= 0x0080;}
                                 else if (GPIOD_ODR == 0x0800){  GPIOD_ODR ^= 0x0800 ; Delay_ms(100); GPIOD_ODR ^= 0x0800; Delay_ms(100); GPIOD_ODR ^= 0x0800; Delay_ms(100); GPIOD_ODR ^= 0x0800;}
                                 else if (GPIOD_ODR == 0x8000){  GPIOD_ODR ^= 0x8000 ; Delay_ms(100); GPIOD_ODR ^= 0x8000; Delay_ms(100); GPIOD_ODR ^= 0x8000; Delay_ms(100); GPIOD_ODR ^= 0x8000;}
                                 else { GPIOD_ODR = GPIOD_ODR << 1 ; }
                               }
                             }
                             else if( GPIOC_ODR != 0){

                                if (flagPORTC == 0 ){
                                    flagPORTC =1;
                                 if (GPIOC_ODR == 0x0008){  GPIOC_ODR ^= 0x0008 ; Delay_ms(100); GPIOC_ODR ^= 0x0008;      Delay_ms(100); GPIOC_ODR ^= 0x0008; Delay_ms(100); GPIOC_ODR ^= 0x0008;}
                                 else if (GPIOC_ODR == 0x0080){  GPIOC_ODR ^= 0x0080 ; Delay_ms(100); GPIOC_ODR ^= 0x0080; Delay_ms(100); GPIOC_ODR ^= 0x0080; Delay_ms(100); GPIOC_ODR ^= 0x0080;}
                                 else if (GPIOC_ODR == 0x0800){  GPIOC_ODR ^= 0x0800 ; Delay_ms(100); GPIOC_ODR ^= 0x0800; Delay_ms(100); GPIOC_ODR ^= 0x0800; Delay_ms(100); GPIOC_ODR ^= 0x0800;}
                                 else if (GPIOC_ODR == 0x8000){  GPIOC_ODR ^= 0x8000 ; Delay_ms(100); GPIOC_ODR ^= 0x8000; Delay_ms(100); GPIOC_ODR ^= 0x8000; Delay_ms(100); GPIOC_ODR ^= 0x8000;}
                                 else { GPIOC_ODR = GPIOC_ODR << 1 ; }
                               }
                             }  else if( GPIOB_ODR != 0){

                                if (flagPORTB == 0 ){
                                    flagPORTB =1;
                                 if (GPIOB_ODR == 0x0008){  GPIOB_ODR ^= 0x0008 ; Delay_ms(100); GPIOB_ODR ^= 0x0008;      Delay_ms(100); GPIOB_ODR ^= 0x0008; Delay_ms(100); GPIOC_ODR ^= 0x0008;}
                                 else if (GPIOB_ODR == 0x0080){  GPIOB_ODR ^= 0x0080 ; Delay_ms(100); GPIOB_ODR ^= 0x0080; Delay_ms(100); GPIOB_ODR ^= 0x0080; Delay_ms(100); GPIOC_ODR ^= 0x0080;}
                                 else if (GPIOB_ODR == 0x0800){  GPIOB_ODR ^= 0x0800 ; Delay_ms(100); GPIOB_ODR ^= 0x0800; Delay_ms(100); GPIOB_ODR ^= 0x0800; Delay_ms(100); GPIOC_ODR ^= 0x0800;}
                                 else if (GPIOB_ODR == 0x8000){  GPIOB_ODR ^= 0x8000 ; Delay_ms(100); GPIOB_ODR ^= 0x8000; Delay_ms(100); GPIOB_ODR ^= 0x8000; Delay_ms(100); GPIOC_ODR ^= 0x8000;}
                                 else { GPIOB_ODR = GPIOB_ODR << 1 ; }
                               }
                             }
                                 



                      }
                      while( Button(&GPIOB_IDR,DownPin,1,ACTIVEstatus) == LOW){

                             if( GPIOD_ODR != 0){

                                if (flagPORTD == 0 ){
                                    flagPORTD =1;
                                 if (GPIOD_ODR == 0x0001){  GPIOD_ODR ^= 0x0001 ; Delay_ms(100); GPIOD_ODR ^= 0x0001;      Delay_ms(100); GPIOD_ODR ^= 0x0001; Delay_ms(100); GPIOD_ODR ^= 0x0001;}
                                 else if (GPIOD_ODR == 0x0010){  GPIOD_ODR ^= 0x0010 ; Delay_ms(100); GPIOD_ODR ^= 0x0010; Delay_ms(100); GPIOD_ODR ^= 0x0010; Delay_ms(100); GPIOD_ODR ^= 0x0010;}
                                 else if (GPIOD_ODR == 0x0100){  GPIOD_ODR ^= 0x0100 ; Delay_ms(100); GPIOD_ODR ^= 0x0100; Delay_ms(100); GPIOD_ODR ^= 0x0100; Delay_ms(100); GPIOD_ODR ^= 0x0100;}
                                 else if (GPIOD_ODR == 0x1000){  GPIOD_ODR ^= 0x1000 ; Delay_ms(100); GPIOD_ODR ^= 0x1000; Delay_ms(100); GPIOD_ODR ^= 0x1000; Delay_ms(100); GPIOD_ODR ^= 0x1000;}
                                 else { GPIOD_ODR = GPIOD_ODR >> 1 ; }
                               }
                             } else if( GPIOC_ODR != 0){

                                if (flagPORTC == 0 ){
                                    flagPORTC =1;
                                 if (GPIOC_ODR == 0x0001){  GPIOC_ODR ^= 0x0001 ; Delay_ms(100); GPIOC_ODR ^= 0x0001;      Delay_ms(100); GPIOC_ODR ^= 0x0001; Delay_ms(100); GPIOC_ODR ^= 0x0001;}
                                 else if (GPIOC_ODR == 0x0010){  GPIOC_ODR ^= 0x0010 ; Delay_ms(100); GPIOC_ODR ^= 0x0010; Delay_ms(100); GPIOC_ODR ^= 0x0010; Delay_ms(100); GPIOC_ODR ^= 0x0010;}
                                 else if (GPIOC_ODR == 0x0100){  GPIOC_ODR ^= 0x0100 ; Delay_ms(100); GPIOC_ODR ^= 0x0100; Delay_ms(100); GPIOC_ODR ^= 0x0100; Delay_ms(100); GPIOC_ODR ^= 0x0100;}
                                 else if (GPIOC_ODR == 0x1000){  GPIOC_ODR ^= 0x1000 ; Delay_ms(100); GPIOC_ODR ^= 0x1000; Delay_ms(100); GPIOC_ODR ^= 0x1000; Delay_ms(100); GPIOC_ODR ^= 0x1000;}
                                 else { GPIOC_ODR = GPIOC_ODR >> 1 ; }
                               }
                             }  else if( GPIOB_ODR != 0){

                                if (flagPORTB == 0 ){
                                    flagPORTB =1;
                                 if (GPIOB_ODR == 0x0001){  GPIOB_ODR ^= 0x0001 ; Delay_ms(100); GPIOB_ODR ^= 0x0001;      Delay_ms(100); GPIOB_ODR ^= 0x0001; Delay_ms(100); GPIOC_ODR ^= 0x0001;}
                                 else if (GPIOB_ODR == 0x0010){  GPIOB_ODR ^= 0x0010 ; Delay_ms(100); GPIOB_ODR ^= 0x0010; Delay_ms(100); GPIOB_ODR ^= 0x0010; Delay_ms(100); GPIOC_ODR ^= 0x0010;}
                                 else if (GPIOB_ODR == 0x0100){  GPIOB_ODR ^= 0x0100 ; Delay_ms(100); GPIOB_ODR ^= 0x0100; Delay_ms(100); GPIOB_ODR ^= 0x0100; Delay_ms(100); GPIOC_ODR ^= 0x0100;}
                                 else if (GPIOB_ODR == 0x1000){  GPIOB_ODR ^= 0x1000 ; Delay_ms(100); GPIOB_ODR ^= 0x1000; Delay_ms(100); GPIOB_ODR ^= 0x1000; Delay_ms(100); GPIOC_ODR ^= 0x1000;}
                                 else { GPIOB_ODR = GPIOB_ODR >> 1 ; }
                               }
                             }




                      }
                      
                      while( Button(&GPIOA_IDR,RightPin,1,ACTIVEstatus) == LOW){




                              if( GPIOD_ODR != 0){

                                if (flagPORTD == 0 ){
                                    flagPORTD =1;
                                 if (GPIOD_ODR == 0x0001){  GPIOD_ODR ^= 0x0001 ; Delay_ms(100); GPIOD_ODR ^= 0x0001;      Delay_ms(100); GPIOD_ODR ^= 0x0001; Delay_ms(100); GPIOD_ODR ^= 0x0001;}
                                 else if (GPIOD_ODR == 0x0002){  GPIOD_ODR ^= 0x0002 ; Delay_ms(100); GPIOD_ODR ^= 0x0002; Delay_ms(100); GPIOD_ODR ^= 0x0002; Delay_ms(100); GPIOD_ODR ^= 0x0002;}
                                 else if (GPIOD_ODR == 0x0004){  GPIOD_ODR ^= 0x0004 ; Delay_ms(100); GPIOD_ODR ^= 0x0004; Delay_ms(100); GPIOD_ODR ^= 0x0004; Delay_ms(100); GPIOD_ODR ^= 0x0004;}
                                 else if (GPIOD_ODR == 0x0008){  GPIOD_ODR ^= 0x0008 ; Delay_ms(100); GPIOD_ODR ^= 0x0008; Delay_ms(100); GPIOD_ODR ^= 0x0008; Delay_ms(100); GPIOD_ODR ^= 0x0008;}
                                 else { GPIOD_ODR = GPIOD_ODR >> 4 ; }
                                 
                               }
                            }
                          
                             else if( GPIOC_ODR != 0){

                                if (flagPORTC == 0 ){
                                    flagPORTC =1;
                                 if (GPIOC_ODR == 0x0001)     { GPIOD_ODR = 0x1000; GPIOC_ODR = 0x0000; flagPORTD =0;}
                                 else if (GPIOC_ODR == 0x0002){ GPIOD_ODR = 0x2000; GPIOC_ODR = 0x0000; flagPORTD =0;}
                                 else if (GPIOC_ODR == 0x0004){ GPIOD_ODR = 0x4000; GPIOC_ODR = 0x0000; flagPORTD =0;}
                                 else if (GPIOC_ODR == 0x0008){ GPIOD_ODR = 0x8000; GPIOC_ODR = 0x0000; flagPORTD =0;}
                                 else { GPIOC_ODR = GPIOC_ODR >> 4 ; }
                               }
                             } 
                             else if( GPIOB_ODR != 0){

                                if (flagPORTB == 0 ){
                                    flagPORTB =1;
                                 if (GPIOB_ODR == 0x0001)     { GPIOC_ODR = 0x1000; GPIOB_ODR = 0x0000; flagPORTC =0;}
                                 else if (GPIOB_ODR == 0x0002){ GPIOC_ODR = 0x2000; GPIOB_ODR = 0x0000; flagPORTC =0;}
                                 else if (GPIOB_ODR == 0x0004){ GPIOC_ODR = 0x4000; GPIOB_ODR = 0x0000; flagPORTC =0;}
                                 else if (GPIOB_ODR == 0x0008){ GPIOC_ODR = 0x8000; GPIOB_ODR = 0x0000; flagPORTC =0;}
                                 else { GPIOB_ODR = GPIOB_ODR >> 4 ; }
                               }
                             }

                      }

                      while( Button(&GPIOD_IDR,LeftPin,1,ACTIVEstatus) == LOW){




                              if( GPIOD_ODR != 0){

                                  if (flagPORTD == 0 ){
                                    flagPORTD =1;
                                 if (GPIOD_ODR == 0x1000)     { GPIOD_ODR = 0; GPIOC_ODR = 0x0001; flagPORTC =0;}
                                 else if (GPIOD_ODR == 0x2000){ GPIOD_ODR = 0; GPIOC_ODR = 0x0002; flagPORTC =0;}
                                 else if (GPIOD_ODR == 0x4000){ GPIOD_ODR = 0; GPIOC_ODR = 0x0004; flagPORTC =0;}
                                 else if (GPIOD_ODR == 0x8000){ GPIOD_ODR = 0; GPIOC_ODR = 0x0008; flagPORTC =0;}
                                 else { GPIOD_ODR = GPIOD_ODR << 4 ; }
                               }
                            }

                             else if( GPIOC_ODR != 0){

                                 if (flagPORTC == 0 ){
                                    flagPORTC =1;
                                 if (GPIOC_ODR == 0x1000)     { GPIOC_ODR = 0; GPIOB_ODR = 0x0001; flagPORTB =0;}
                                 else if (GPIOC_ODR == 0x2000){ GPIOC_ODR = 0; GPIOB_ODR = 0x0002; flagPORTB =0;}
                                 else if (GPIOC_ODR == 0x4000){ GPIOC_ODR = 0; GPIOB_ODR = 0x0004; flagPORTB =0;}
                                 else if (GPIOC_ODR == 0x8000){ GPIOC_ODR = 0; GPIOB_ODR = 0x0008; flagPORTB =0;}
                                 else { GPIOC_ODR = GPIOC_ODR << 4 ; }
                               }
                             }
                             else if( GPIOB_ODR != 0){

                               if (flagPORTB == 0 ){
                                    flagPORTB =1;
                                 if (GPIOB_ODR == 0x1000){  GPIOD_ODR ^= 0x1000 ; Delay_ms(100); GPIOD_ODR ^= 0x1000;      Delay_ms(100); GPIOD_ODR ^= 0x0001; Delay_ms(100); GPIOD_ODR ^= 0x1000;}
                                 else if (GPIOB_ODR == 0x2000){  GPIOD_ODR ^= 0x0002 ; Delay_ms(100); GPIOD_ODR ^= 0x2000; Delay_ms(100); GPIOD_ODR ^= 0x2000; Delay_ms(100); GPIOD_ODR ^= 0x2000;}
                                 else if (GPIOB_ODR == 0x4000){  GPIOD_ODR ^= 0x4000 ; Delay_ms(100); GPIOD_ODR ^= 0x4000; Delay_ms(100); GPIOD_ODR ^= 0x4000; Delay_ms(100); GPIOD_ODR ^= 0x4000;}
                                 else if (GPIOB_ODR == 0x8000){  GPIOD_ODR ^= 0x8000 ; Delay_ms(100); GPIOD_ODR ^= 0x8000; Delay_ms(100); GPIOD_ODR ^= 0x8000; Delay_ms(100); GPIOD_ODR ^= 0x8000;}
                                 else { GPIOB_ODR = GPIOB_ODR << 4 ; }

                               }
                             }

                      }


                     flagPORTD =0;
                     flagPORTC =0;
                     flagPORTB =0;
                     
                    
                    
                    
                     
       
       
       
                     
                     
                   }
       

       
       }