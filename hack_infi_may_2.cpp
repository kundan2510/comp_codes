#include <bits/stdc++.h>
int main()
{
	int t;
	long long a,b,c,d,e,f,g,h,i,j,k,l,det;
	scanf("%d",&t);
	while(t--)
	{
		det = 0;
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j,&k,&l);
		a = a - j;
		d = d - j;
		g = g - j;
		b = b - k;
		e = e - k;
		h = h - k;
		c = c - l;
		f = f - l;
		i = i - l;
		det += a*((e*i) - (h*f));
		det -= b*((d*i) - (g*f));
		det += c*((d*h) - (e*g));

		if(abs(det) < 1)
		{
			printf("YES\n");
		}
		else
		{
			printf("N0\n");
		}
	}
	return 0;
}