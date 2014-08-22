#include <stdio.h>
int prime[200001];
void generate_prime()
{
  int i=0;
  int j;
  while(i<200001)
  {
    prime[i]=1;
    i++;
  }
  prime[0]=0;
  prime[1]=0;
  i=0;
  while(i<448) //448 = sqrt(200001)
  {
    while (prime[i] == 0)
      i++;
    j=i+1;
    while(j<200001)
    {
      if(j%i == 0)
        prime[j]=0;
      j++;
    }
    i++;

  }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,i;
    generate_prime();
    scanf("%d",&n);
    n--;
    int count = 0;
    for(i = 0;i< 2*n;i++)
    {
      if(prime[i] == 1)
      {
        if(i <= n)
        {
          count = (count + i + 1) % 1000000007;
        }
        else
        {
          count = (count + (2*n) + 1 - i ) % 1000000007;
        }
      }
    }
    printf("%d\n",count);
    return 0;
}