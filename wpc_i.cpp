#include <bits/stdc++.h>
long long unsigned int gcd(long long unsigned int a,long long unsigned int b)
{
	long long unsigned int t;
	if (b > a)
	{
		t = a;
		a = b;
		b = t;
	}
	while(b != 0)
	{
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}
int main()
{
	int t;
	long long unsigned int m,n,k,p,res;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%llu%llu",&m,&n);
		k = (m/gcd(m,n));
		p = (n/gcd(m,n));
		res = (k/gcd(k,p))* (p/(gcd(k,p)));
		printf("%llu\n",res);
	}
	return 0;
}