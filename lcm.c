#include<stdio.h>
void main()
{
	int num1,num2,i=2,ans=1;
	printf("enter num 1 :");
	scanf("%d",&num1);
	printf("enter num2 :");
	scanf("%d",&num2);
	while(num1!=1 || num2!=1)
	{
	//	if(num1==1 && num2==1)break;
		if(num1%i==0 && num2%i==0)
		{
			num1=num1/i;
			num2=num2/i;
			ans=ans*i;
		}
		else if(num1%i==0)
		{
			num1=num1/i;
			ans=ans*i;
		}
		else if(num2%i==0)
		{
			num2=num2/i;
			ans=ans*i;
		}
		else 
		{
			i++;	
		}
	
	}
	printf("%d",ans);
}
