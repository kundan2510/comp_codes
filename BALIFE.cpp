#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,rem,avg,res;
	scanf("%d",&n);
	while(n != -1)
	{
		rem = 0;
		avg = 0;
		res = 0;
		int input[n];
		for (i = 0; i < n; ++i)
		{
			scanf("%d",&input[i]);
			avg += (rem + input[i])/n;
			rem = (rem + input[i])%n;
		}
		if(rem != 0)
		{
			printf("-1\n");
		}
		else
		{
			for (i = 0; i < n; ++i)
			{
				input[i] -= avg;
			}
			for (i = 1; i < n; ++i)
			{
				input[i] += input[i-1];
			}
			for (i = 0; i < n; ++i)
			{
				res = max(abs(input[i]),res);
			}
			printf("%d\n",res);
		}
		scanf("%d",&n);
	}
	return 0;
}