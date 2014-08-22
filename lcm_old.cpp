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
	long long unsigned int m,n,k;
	scanf("%llu%llu",&m,&n);
	k = (m/gcd(m,n))*(n/gcd(m,n));
	printf("%llu\n",k);
	return 0;
}