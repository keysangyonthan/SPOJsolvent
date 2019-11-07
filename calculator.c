#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main(){
  float num1,num2,result;
  int opt;
  scanf("%f %f",&num1,&num2);
  printf("1.Addition");
  printf("2.Subtraction");
  printf("3.Multiplication");
  printf("4.Divison");
  scanf("%d",&opt);
  switch(opt){
  case 1:printf("%f",num1+num2);
  case 2:printf("%f",num1-num2);
  case 3:printf("%f",num1*num2);
  case 4:printf("%f"num1/num2);
  }
}
