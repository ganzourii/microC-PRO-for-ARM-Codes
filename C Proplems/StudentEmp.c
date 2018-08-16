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

struct human {
	
	uint32 Age;
	char Name [50];
	uint32 ID;
	char Gender;
};

struct student {
    struct human h;
	uint32 sub1grade;
	uint32 sub2grade;
	uint32 grade;
};

typedef struct {
	struct human h;
	uint32 Salary;
	uint32 Workhrs;
	uint32 bouns ;
}emp;



void main (void){
	char khara[20];
	struct student s[3];
	emp e[3];
	uint32 i;
	for(i=0;i<3;i++){
		printf("Enter Name student no.%d   :",i+1);
		scanf("%s",&s[i].h.Name);
	    printf("Enter Age student no.%d    : ",i+1);
		scanf("%d",&s[i].h.Age);
		printf("Enter ID student no.%d     : ",i+1);
		scanf("%d",&s[i].h.ID);
		printf("Enter Gender student no.%d :" ,i+1);
		scanf(" %c",&s[i].h.Gender);
        printf("Enter Subject 1 grade      : ");
		scanf("%d",&s[i].sub1grade);
        printf("Enter Subject 2 grade      : ");
		scanf("%d",&s[i].sub2grade);
		s[i].grade = s[i].sub1grade + s[i].sub2grade ;
	}
	
		for(i=0;i<3;i++){
		printf("Enter Name employee no.%d  : " ,i+1);
        scanf("%s",&e[i].h.Name);
	    printf("Enter Age employee no.%d   :",i+1);
		scanf("%d",&e[i].h.Age);
		printf("Enter ID employee no.%d    :",i+1);
		scanf("%d",&e[i].h.ID);
		printf("Enter Gender employee no.%d: ",i+1);
		scanf(" %c",&e[i].h.Gender);
        printf("Enter Working hours        :");
		scanf("%d",&e[i].Workhrs);
        printf("Enter Salary               :");
		scanf("%d",&e[i].Salary);
		if (e[i].Workhrs >8 ) e[i].bouns = (e[i].Workhrs-8)*(0.1*e[i].Salary)*(e[i].h.Age/24);
		else e[i].bouns = 0;

	}
	
	
	for(i=0;i<3;i++){
		printf("Name employee no. %d is %s\n   :",i+1,e[i].h.Name);
	    printf("Age employee no. %d is %d\n    :",i+1,e[i].h.Age);
		printf("ID employee no. %d is %d\n     :",i+1,e[i].h.ID);
		printf("Gender employee no. %d is %c\n :",i+1,e[i].h.Gender);
        printf("Working hours is %d\n          :",e[i].Workhrs);
        printf("Salary is %d\n                 :",e[i].Salary);
        printf("Bouns is %d\n                  :",e[i].bouns);
	}
	for(i=0;i<3;i++){
		printf("Name student no. %d is %s\n    :",i+1,s[i].h.Name);
	    printf("Age student no. %d is %d\n     :",i+1,s[i].h.Age);
		printf("ID student no. %d is %d\n      :",i+1,s[i].h.ID);
		printf("Gender student no. %d is %c\n  :",i+1,s[i].h.Gender);
        printf("Subject one grade is %d\n      :",s[i].sub1grade);
        printf("Subject two grade is %d\n      :",s[i].sub2grade);
        printf("Total grade is %d\n            :",s[i].grade);
	}
	
	
	
	
	
	
	
}