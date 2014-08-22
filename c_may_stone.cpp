#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;
	long long k;
	scanf("%d%lld",&n,&k);
	long long input[n];
	scanf("%lld",&input[0]);
	long long minm = input[0];
	long long maxm = input[0];
	for(i=1;i<n;i++)
	{
		scanf("%lld",&input[i]);
		minm = min(minm,input[i]);
		maxm = max(maxm,input[i]);
	}
	if(k == 0)
	{
		for(i=0;i<n-1;i++)
		{
			printf("%lld ",input[i]);
		}
		 printf("%lld",input[i]);
	}
	else if (k%2 == 0)
	{
		for(i=0;i<n-1;i++)
		{
			printf("%lld ",input[i] - minm);
		}
		printf("%lld",input[i] - minm);
	}
	else
	{
		for(i=0;i<n-1;i++)
		{
			printf("%lld ",maxm-input[i]);
		}
		printf("%lld",maxm-input[i]);
	}
	return 0;
}
