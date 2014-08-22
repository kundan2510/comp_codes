#include <bits/stdc++.h>
typedef	long long	ll;
const ll M=10000007;

ll modpow(ll a,ll n){	// calc a^n (mod M)
	ll r=1;
	for(ll x=a;n;n>>=1,x=(x*x)%M) if(n&1) r=(r*x)%M;
	return r;
}
int main()
{
	ll n,k,ans;
	scanf("%lld%lld",&n,&k);
	while(n != 0)
	{
		ans = ((2*(modpow((n-1)%M,k)))%M + (2*(modpow((n-1)%M,(n-1))))%M + modpow(n%M,n) + modpow(n%M,k))%M;
		printf("%lld\n",ans);	
		scanf("%lld%lld",&n,&k);
	}
	return 0;
}