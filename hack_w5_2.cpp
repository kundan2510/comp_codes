#include <bits/stdc++.h>
int main()
{
	int a,b,x,t,temp,temp2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&x);
		temp = pow(a,b);
		temp2 = temp % x;
		if(2*temp2 <= x)
		{
			printf("%d\n",temp - temp2 );
		}
		else
		{
			printf("%d\n",temp + x - temp2 );
		}
	}
	return 0;
}