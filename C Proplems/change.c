#include <stdio.h>

void main (void){
	int i;
	printf("Even Numbers:\n");

	for(i=1;i<=10;i++){
	
    	if (i%2 ==0){
		 printf("%d\n",i);
			
	    }
	
	
	}
	printf("Odd Numbers:\n");

	for(i=1;i<=10;i++){
	
    	if (i%2 != 0){
		 printf("%d\n",i);
			
	    }
	
	
	}
}