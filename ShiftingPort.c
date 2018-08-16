#define ForwardSwitchPin 0
#define BackSwitchPin 1
#define ACTIVEstatus 1
#define HIGH 255
void main() {
      char flag =0;
        GPIO_Digital_Input(&GPIOA_IDR,_GPIO_PINMASK_0);
        GPIO_Digital_Output(&GPIOC_ODR,_GPIO_PINMASK_ALL);
        GPIOC_ODR= 0;
        
                while(1) {

                       while ( Button(&GPIOA_IDR,ForwardSwitchPin,100,ACTIVEstatus) == HIGH) {
                       
                         if (flag == 0 ){
                            flag =1;
                             if ( GPIOC_ODR == 0){
                                 GPIOC_ODR= 0x0001;
                                 }
                              else {
                           GPIOC_ODR = (GPIOC_ODR << 1);
                                     }
                         }
                                      
                       }
                       flag =0;

                }
}