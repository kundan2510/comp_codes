#include <stdio.h>
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int temp,sum,i,rem;
    for(i = 1; i < 99999; i++)
    {
        temp = i;
        sum = 0;
        while( temp != 0 )
       {
          rem = temp%10;
          sum = sum + rem*rem*rem;
          temp = temp/10;
       }
       if(sum == i)
       {
           printf("%d\n",i);
       }
    }
    return 0;
}