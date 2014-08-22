#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,i,j,k,n;
	long double C,X,F,ANS;
	scanf("%d",&t);
	for (i = 0; i < t; i++)
	{
		cin >> C >> X >> F;
		n = 0;
		ANS = 0.00;
		while(F*X > C*(2 + (n+1)*F))
		{
			ANS = ANS + C/(2 + n*F);
			n++;
		}
		if(n != 0)
			n--;
		ANS = ANS + (X-C)/(2 + n*F);
		printf("%Lf\n",ANS);
	}
	return 0;
}