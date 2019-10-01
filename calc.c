#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
	float a, b, res;
	char choice, ch;
	do
	{
		printf("1.Addition\n");
		printf("2.Subtraction\n");
		printf("3.Multiplication\n");
		printf("4.Division\n");
		printf("5.Exit\n\n");
		printf("Enter Your Choice : ");
		scanf("%c",&choice);
		switch(choice)
		{
			case '1' : printf("Enter two number : ");
				scanf("%f%f",&a,&b);
				res=a+b;
				printf("Result = %f",res);
				break;
			case '2' : printf("Enter two number : ");
				scanf("%f%f",&a,&b);
				res=a-b;
				printf("Result = %f",res);
				break;
			case '3' : printf("Enter two number : ");
				scanf("%f%f",&a,&b);
				res=a*b;
				printf("Result = %f",res);
				break;
			case '4' : printf("Enter two number : ");
				scanf("%f%f",&a,&b);
				res=a/b;
				printf("Result = %f",res);
				break;
			case '5' : exit(0);
				break;
			default : printf("Wrong Choice..!!");
				break;
		}
		printf("\n------------------------------------\n");
	}while(choice!=5 && choice!=getchar());
	getch();
}
