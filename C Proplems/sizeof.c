#include <stdio.h>
#include <math.h>

typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long int uint32;
typedef signed char sint8;
typedef signed short int sint16;
typedef signed long int sint32;
typedef float  f32;
typedef double f64;

struct complex {
	
	uint32 real;
	uint32 img;
};

struct complex AddComplex (struct complex a1,struct complex a2){
	
	struct complex result;
	
	result.real = a1.real + a2.real;
	result.img = a1.img + a2.img;
	
	return result;
	
}
	struct complex SubComplex (struct complex a1,struct complex a2){
	
	struct complex result;
	
	result.real = a1.real - a2.real;
	result.img = a1.img - a2.img;
	
	return result;
	
}
void main (void){
	
struct complex Num1,Num2,result;
scanf ("%d %d",&Num1.real,&Num1.img);
printf("enter second number\n");
scanf ("%d %d",&Num2.real,&Num2.img);
result =AddComplex(Num1,Num2);
printf("Addition = %d + j %d\n",result.real,result.img);
result =SubComplex(Num1,Num2);
if (Num1.img >= Num2.img) printf("Subtract = %d + j %d\n",result.real,result.img);
else printf("Subtract = %d - j %d\n",result.real,abs(result.img));
}