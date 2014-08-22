#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,i,j,l,m;
	long long unsigned k;
	int n;
	scanf("%d",&t);
	int mod10[1000];
	while(t--)
	{
		scanf("%d",&n);
		mod10[0] = 1;
		for(i = 1;i<1000;i++)
		{
			mod10[i] = (mod10[i-1] * 10) % n;
			//printf("%d ",mod10[i] );
		}
		//printf("\n");
		for(i = int(pow(2,log10(n)));;)
		{
			j = 0;
			for(l=0,k=i;k > 0;k = k>>1,l++)
			{
				
				if(k&1)
				{
					j = (j + mod10[l]) % n;
				}
			}
			if(j == 0)
			{
				//printf("%s\n",res );
				k = 1 << (l-1);
				for(;k > 0; k = k>>1)
				{
					printf("%d",!(!(k&i)));
				}
				break;
			} 
			else
			{
				i += pow(2,(log10(n - j)));
			}
		}
		printf("\n");
	}
	return 0;
}