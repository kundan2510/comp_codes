#include <bits/stdc++.h>
int main()
{
	int t,n,k,count=0;
	scanf("%d%d",&n,&k);
	while(n--)
	{
		scanf("%d",&t);
		if(!(t%k))
		{
			count++;
		}
	}
	printf("%d\n",count );
	return 0;
}