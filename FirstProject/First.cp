#line 1 "F:/Ganzouri/First/First.c"
void main() {

 GPIO_Digital_Output(&GPIOD_ODR,_GPIO_PINMASK_ALL);
 GPIO_Digital_Output(&GPIOA_ODR,_GPIO_PINMASK_ALL);
 GPIO_Digital_Output(&GPIOC_ODR,_GPIO_PINMASK_ALL);
 GPIO_Digital_Output(&GPIOB_ODR,_GPIO_PINMASK_ALL);
 GPIO_Digital_Output(&GPIOE_ODR,_GPIO_PINMASK_ALL);
 GPIOD_ODR =0xffff;
 GPIOA_ODR =0xffff;
 GPIOB_ODR =0xffff;
 GPIOC_ODR =0xffff;
 GPIOE_ODR =0xffff;

 while (1) {

 GPIOD_ODR ^=0xffff;
 GPIOA_ODR ^=0xffff;
 GPIOB_ODR ^=0xffff;
 GPIOC_ODR ^=0xffff;
 GPIOE_ODR ^=0xffff;
 Delay_ms(200);


 }







}
