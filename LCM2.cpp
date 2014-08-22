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
	long long unsigned m,lcmn,n,g,g_m,g_n,res,k1,k2,k1_dash,k2_dash;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%llu%llu",&m,&n);
		lcmn = lcm(m,n);
		g_n = lcmn / n;
		g_m = lcmn / m;
		k1 =  lcmn / lcm(m,g_m);
		k2 = lcmn / lcm(n,g_n);
		k1_dash = k1*g_m;
		k2_dash = k2*g_n;
		res = lcm(k1_dash,k2_dash);
		printf("%llu\n",res);
	}
	return 0;
}