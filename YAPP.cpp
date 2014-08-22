#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;
ll modpow(int a,int n){	// calc a^n (mod M)
	int r=1;
	for(ll x=a;n;n>>=1,x=(x*x)%M) if(n&1) r=(r*x)%M;
	return r;
}
int main()
{
	int t,n;
	long long ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans = modpow(2,n-1);
		printf("%lld\n",ans);
	}
	return 0;
}