#include<stdio.h>
int main()
{
int a,b,e,i,p,test,tcount,count;
scanf("%d",&test);
for(tcount=1;tcount<=test;tcount++)
{
 count=2;
 scanf("%d",&a);
 if (a!=1)
 {
  for(i=3,p=3;i<p;i=i+2)
  {
   b=p%i;
   if(i==(p-1)&&(p%2)!=0)
   {
     count++;
     b=0;
     if(count==a)
     {
       printf("%d\n",p);
       break;
     }
   }
   if(b==0)
   {
    i=1;
    p=p+2;
    continue;
   }
 }
 }
 else
  printf("2");
}
return 0;
}
