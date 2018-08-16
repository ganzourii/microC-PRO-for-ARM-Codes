#include <stdio.h>

void main (void){
    char a;
	int x,y;
	int exit=0;

	while( exit != 1){
		
	printf("Enter operation \n");
	
	scanf (" %c",&a);
	
	printf("Enter operands  \n");
	
    scanf ("%d",&x);
	
	scanf ("%d",&y);
	
	switch(a){
		
		case '+' : printf("%d + %d = %d\n",x,y,x+y);
		break;
		
		case '-' : printf("%d - %d = %d\n",x,y,x-y);
        break;
		
		case '*' : printf("%d * %d = %d\n",x,y,x*y);
		break;
		
		case '/' : if (y == 0) {printf("you can't divide %d/%d\n",x,y);
			break;}
		
		printf("%d / %d = %d",x,y,x/y);
        break;
		
		case '%' : printf(" %d % %d = %d\n",x,y,x%y);
		break;
	}
	printf("Enter 1 if you want to exit any char if you want continue ");
	scanf("%d",&exit);
	}
}