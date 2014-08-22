#include <bits/stdc++.h>
long long gcd(long long a, long long b)
{
	long long temp;
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
int main()
{
	long long m,n,g;
	scanf("%lld%lld",&m,&n);
	g = gcd(m,n);
	printf("gcd = %lld\nlcm = %lld\n",g,(m*n)/g );
	return 0;
}