#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("We are printing Armstrong numbers from 1 to 1000\n");
    int i;
    int a,b,c,AN;
    i=001;
    while(i<=999)
    {

    a=i%10;
    b=i%100;
    b=(b-a)/10;
    c=i%100;
    AN = (a*a*a)+(b*b*b)+(c*c*c);
    if(AN==i);
    {
        printf("\Armstrong number is %d",i);
    }
    }
    return 0;
}
