#include <stdio.h>
#include <stdlib.h>


int main()
{
    int add,sub,div,mul;

    int a,b,c,i,choice;


    char option;

    printf("This is a calculator\n");
do
       {

        printf("Enter your choice:\n1.For addition\n2.For Subtraction\n3.For multiplication\n4.For Division\n");
    scanf("%d",&choice);
    printf("Enter two numbers\n");
    scanf("%d %d",&a,&b);
    switch(choice)
    {
    case 1:
     c=a+b;
     printf("Sum of two numbers is %d\n",c);
    break;
    case 2:
        c=a-b;
        printf("difference of two numbers is %d\n",c);
break;

    case 3:
        c=a*b;
        printf("Product of two numbers is %d\n",c);
        break;

    case 4:
        c=a/b;
        printf("Division of two numbers is %d\n");
break;

    default:
    printf("Wrong input\n");
    }
    printf("Do you want to continue: Y or N?\n");
    option=getche();
}while(option=='Y');


    return 0;
}

