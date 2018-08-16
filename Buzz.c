

void Buzzer(unsigned int Frequency, float dutycycle){
    int time;
    int timeOn;
    int timeOff;
    int counter = 0;
    int i;
    
    GPIO_Digital_Output(&GPIOE_ODR,_GPIO_PINMASK_14);
    
    time = 1000/Frequency;  //ms time
    
    timeOn= dutycycle * time;
    
    timeOff = time - timeOn;


            GPIOE_ODR |= (1 << 14);
            for (i=0; i<(timeOn*1000);i++){
             Delay_us(1);
            }
            
            GPIOE_ODR &= ~(1 << 14);
            for (i=0; i<(timeOff*1000);i++){
             Delay_us(1);
            }





}