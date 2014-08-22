#include <bits/stdc++.h>
int main()
{
	int t,count;
	unsigned long long int temp,n,m,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%llu%llu%llu",&n,&k,&m);
		count = 0;
		temp = n;
		while(temp <= m)
		{
			count++;
			temp = temp*k;
		}
		count--;
		if (count == -1)
		{
			count = 0;
		}
		printf("%d\n", count);
	}
	return 0;
}