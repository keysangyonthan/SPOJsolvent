#include <stdio.h>
#include <stdlib.h>

int main()
{
   int rem,i,t;
   scanf("%d",&t);
   int n[t],sum[t];
   for(i=0;i<t;i++)
   {
       scanf("%d",&n[i]);
   }
   for(i=0;i<t;i++)
   {
       sum[i]=0;
       while(n[i]!=0)
       {
           rem=n[i]%10;
           sum[i] = sum[i]*10 + rem;
           n[i] = n[i]/10;
       }
   }
   for(i=0;i<t;i++)
   {
       printf("%d\n",sum[i]);
   }
}

