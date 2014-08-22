#include<map>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<string>
#include<vector>
#include<climits>
#include<complex>
#include<cstdlib>
#include<cstring>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>

#define	mp			make_pair
#define	pb			push_back
#define	pf			push_front
#define	rep(i,n)	for(int i=0;i<n;i++)

using namespace std;

typedef	long long			ll;
typedef	unsigned long long	ull;
typedef	vector<bool>		vb;
typedef	vector<int>			vi;
typedef	vector<vb>			vvb;
typedef	vector<vi>			vvi;
typedef	pair<int,int>		pii;

const int INF=1<<29;
const double EPS=1e-9;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

const ll M=1000003;

ll modpow(int a,int n){	// calc a^n (mod M)
	int r=1;
	for(ll x=a;n;n>>=1,x=(x*x)%M) if(n&1) r=(r*x)%M;
	return r;
}

int inv(int a){	// find x s.t. a*x=1 (mod M) (M:prime)
	return modpow(a,M-2);
}

ll modnCr(ll n,ll r){	// calc nCr (mod M) (M:prime)
	if(n<r)		return 0;
	if(n-r<r)	r=n-r;

	ll res=1;
	for(int i=r;i>0;i--){
		res=(res*((n-i+1)%M))%M;
		res=(res*inv(i))%M;
	}
	return res;
}

int main(){
	int T;	scanf("%d",&T);
	while(T--){
		ll n,k;
		int p;	scanf("%lld%lld%d",&n,&k,&p);

		ll f[100];	// f[r] = kHr[r] : number of r-multicombination from k (r<p)
		rep(r,p)	f[r]=modnCr(k+r-1,r);

		int len,a[60];
		{
			int i=0;
			for(ll nn=n;nn;nn/=p)	a[i++]=nn%p;
			len=i;
		}

// printf("n=%lld, p=%d, len=%d\n",n,p,len);
// printf("p-digit: ");rep(i,len)printf("%d ",a[len-i-1]);puts("");
// rep(i,p)printf("f(%d) = %lld\n",i,f[i]);
		ll dp[60][100];
		dp[0][0]=f[0];
		for(int j=1;j<p;j++)	dp[0][j]=(dp[0][j-1]+f[j])%M;
		for(int i=1;i<len;i++){
			dp[i][0]=(f[0]*dp[i-1][p-1])%M;
			for(int j=1;j<p;j++){
				dp[i][j]=(dp[i][j-1]+(f[j]*dp[i-1][p-1])%M)%M;
			}
		}

		ll ans=dp[0][a[0]];
		for(int i=1;i<len;i++){
			if(a[i]==0)	continue;
			ans=(dp[i][a[i]-1]+(f[a[i]]*ans)%M)%M;
		}
		printf("%lld\n",ans);
	}

	return 0;
}
