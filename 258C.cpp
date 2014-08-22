#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int solve(LL n, LL k, LL d1,LL d2)
{
	LL w1 = (2*d1 + d2 + k)/3;
	LL w2 = ((-1)*d1 + d2 + k)/3;
	LL w3 = ((-1)*d1 +(-2)*d2 + k)/3;
	//printf("%lld %lld %lld\n",w1, w2, w3 );
	if(w1 >= w2 && w2 >= w3 && w1 >= 0 && w2 >= 0 && w3 >= 0 && ((w1 + w2 + w3) == k) && (w1 <= n/3)&&(w2<=n/3)&&(w3<=n/3))
	{
		return 1;
	}
	w1 = (2*d1 - d2 + k)/3;
	w2 = ((-1)*d1 - d2 + k)/3;
	w3 = ((-1)*d1 +2*d2 + k)/3;
	//printf("%lld %lld %lld\n",w1, w2, w3 );
	if(w1 >= w2 && w2 <= w3 && w1 >= 0 && w2 >= 0 && w3 >= 0 && ((w1 + w2 + w3) == k) && (w1 <= n/3)&&(w2 <= n/3)&&(w3 <= n/3))
	{
		return 1;
	}
	w1 = (-2*d1 + d2 + k)/3;
	w2 = (d1 + d2 + k)/3;
	w3 = (d1 -2*d2 + k)/3;
	//printf("%lld %lld %lld\n",w1, w2, w3 );
	if(w1 <= w2 && w2 >= w3 && w1 >= 0 && w2 >= 0 && w3 >= 0 && ((w1 + w2 + w3) == k) && (w1 <= n/3)&&(w2<=n/3)&&(w3<=n/3))
	{
		return 1;
	}
	w1 = (-2*d1 - d2 + k)/3;
	w2 = (d1 - d2 + k)/3;
	w3 = (d1 + 2*d2 + k)/3;
	//printf("%lld %lld %lld\n",w1, w2, w3 );
	if(w1 <= w2 && w2 <= w3 && w1 >= 0 && w2 >= 0 && w3 >= 0 && ((w1 + w2 + w3) == k) && (w1 <= n/3)&&(w2 <= n/3)&&(w3 <= n/3))
	{
		return 1;
	}
	return 0;
} 
int main()
{
	int t;
	int r;
	LL n,k,d1,d2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&n,&k,&d1,&d2);
		if(n%3 == 0)
		{
			r = solve(n,k,d1,d2);
			if(r)
			{
				printf("yes\n");
			}
			else
			{
				printf("no\n");
			}
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}