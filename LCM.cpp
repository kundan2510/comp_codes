#include <bits/stdc++.h>
long long unsigned gcd(long long unsigned a, long long unsigned b)
{
	long long unsigned temp;
	if (a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	if (b == 0)
	{
		return a;
	}
	else
		return gcd(b,a % b);
}
long long unsigned lcm(long long unsigned a, long long unsigned b)
{
	return (a/gcd(a,b))*b;
}
int main()
{
	int t;
	long long unsigned m,n,g,g_m,g_n,res;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%llu%llu",&m,&n);
		g = gcd(m,n);
		g_m = (n*gcd(m,n/g))/g;
		g_n = (m*gcd(n,m/g))/g;
		res = (g_m*g_n)/gcd(g_m,g_n);
		printf("%llu\n",res);
	}
	return 0;
}