#line 1 "F:/Ganzouri/Second/Second.c"





void main() {
char flag=0;
 GPIO_Digital_Input(&GPIOD_IDR,_GPIO_PINMASK_0);
 GPIO_Digital_Output(&GPIOC_ODR,_GPIO_PINMASK_ALL);
 GPIOD_ODR = 0;

 while(1) {

 if ( Button(&GPIOD_IDR, 0 ,1, 1 ) ==  255 ) {
 if (flag == 0){
 flag=1;
 GPIOC_ODR ^=0xFFFF;
 }
 } else {flag =0;}


 }
}
