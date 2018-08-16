_main:
;Second.c,6 :: 		void main() {
SUB	SP, SP, #4
;Second.c,7 :: 		char flag=0;
MOVS	R0, #0
STRB	R0, [SP, #0]
;Second.c,8 :: 		GPIO_Digital_Input(&GPIOD_IDR,_GPIO_PINMASK_0);
MOVW	R1, #1
MOVW	R0, #lo_addr(GPIOD_IDR+0)
MOVT	R0, #hi_addr(GPIOD_IDR+0)
BL	_GPIO_Digital_Input+0
;Second.c,9 :: 		GPIO_Digital_Output(&GPIOC_ODR,_GPIO_PINMASK_ALL);
MOVW	R1, #65535
MOVW	R0, #lo_addr(GPIOC_ODR+0)
MOVT	R0, #hi_addr(GPIOC_ODR+0)
BL	_GPIO_Digital_Output+0
;Second.c,10 :: 		GPIOD_ODR = 0;
MOVS	R1, #0
MOVW	R0, #lo_addr(GPIOD_ODR+0)
MOVT	R0, #hi_addr(GPIOD_ODR+0)
STR	R1, [R0, #0]
;Second.c,12 :: 		while(1) {
L_main0:
;Second.c,14 :: 		if  ( Button(&GPIOD_IDR,OnSwitchPin,1,ACTIVEstatus) == HIGH) {
MOVS	R3, #1
MOVS	R2, #1
MOVS	R1, #0
MOVW	R0, #lo_addr(GPIOD_IDR+0)
MOVT	R0, #hi_addr(GPIOD_IDR+0)
BL	_Button+0
CMP	R0, #255
IT	NE
BNE	L_main2
;Second.c,15 :: 		if (flag == 0){
LDRB	R0, [SP, #0]
CMP	R0, #0
IT	NE
BNE	L_main3
;Second.c,16 :: 		flag=1;
MOVS	R0, #1
STRB	R0, [SP, #0]
;Second.c,17 :: 		GPIOC_ODR ^=0xFFFF;
MOVW	R0, #lo_addr(GPIOC_ODR+0)
MOVT	R0, #hi_addr(GPIOC_ODR+0)
LDR	R1, [R0, #0]
MOVW	R0, #65535
EORS	R1, R0
MOVW	R0, #lo_addr(GPIOC_ODR+0)
MOVT	R0, #hi_addr(GPIOC_ODR+0)
STR	R1, [R0, #0]
;Second.c,18 :: 		}
L_main3:
;Second.c,19 :: 		} else {flag =0;}
IT	AL
BAL	L_main4
L_main2:
MOVS	R0, #0
STRB	R0, [SP, #0]
L_main4:
;Second.c,22 :: 		}
IT	AL
BAL	L_main0
;Second.c,23 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
