#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;

long long modpow(int a,int n){	// calc a^n (mod M)
	int r=1;
	for(long long x=a;n;n>>=1,x = (x*x)%M) 
		if(n&1) 
			r=(r*x)%M;
	return r;
}
int inv(int a){	// find x s.t. a*x=1 (mod M) (M:prime)

	return modpow(a,M-2);

}
long long  modnCr(long long n,long long r){	// calc nCr (mod M) (M:prime)
	if(n<r)		return 0;

	if(n-r<r)	r=n-r;

	long long res=1;
	for(int i=r;i>0;i--)
	{
		res=(res*((n-i+1)%M))%M;
		res=(res*inv(i))%M;
	}
	return res;
}
int main()
{
	int t;

	long long n, m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		printf("%lld\n", modnCr(n+m-1,m-1));
	}
	return 0;
}