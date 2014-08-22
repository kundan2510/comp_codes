#include <bits/stdc++.h>
int main()
{
	int n,i,t,count,j,temp,money;
	scanf("%d",&n);
	scanf("%d",&money);
	bool valid[n];
	count = 0;
	memset(valid,0,sizeof(valid));
	for (i = 0; i < n; ++i)
	{
		scanf("%d",&t);
		for(j = 0; j < t;j++)
		{
			scanf("%d",&temp);
			if(money > temp)
			{
				valid[i] = true;
			}
		}
		if(valid[i])
			count++;
	}
	printf("%d\n",count );
	for(i = 0; i < n; i++)
	{
		if(valid[i])
		{
			printf("%d ",i+1 );
		}
	}
	return 0;
}