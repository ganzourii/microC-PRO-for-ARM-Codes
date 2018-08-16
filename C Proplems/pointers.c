 #include<stdio.h>
#include<math.h>
typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long int uint32;
typedef signed char sint8;
typedef signed short int sint16;
typedef signed long int sint32;
typedef float  f32;
typedef double f64;

typedef struct {
    
	uint32 Num1;
	uint32 Num2;

}Values;


void main (void) {

Values v1,*ptr;
ptr = &v1;

scanf("%d %d",&(ptr->Num1),&(ptr->Num2));
printf("Number 1 : %d \nNumber 2 : %d\nNumber 1 : %d \nNumber 2 : %d\n",(ptr->Num1),(ptr->Num2),v1.Num1,v1.Num2);






}