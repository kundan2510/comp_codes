#include <bits/stdc++.h>
using namespace std;
int main()
{
	int p,i,x1,x2,found,anomaly_found,a,x,temp,alpha,beta;
	bool found1,found2;
	printf("Enter prime p : ");
	scanf("%d",&p);
	
	while(p > 1)
	{
		int quad_res[(p-1)/2];
		for (i = 1; i < p-i; ++i)
		{
			quad_res[i] = (i*i)%p;
		}
		sort(quad_res + 1,quad_res+((p-1)/2));
		anomaly_found = 0;
		a = 1;
		while(a<p)
		{
			x = a;
			temp = 1;
			found1 = binary_search(quad_res + 1,quad_res+((p-1)/2),a);
			if(!found1)
			{
				a++;
				continue;
			}
			found = 0;

			while(temp < p)
			{
				x1 = (x - temp) % p;
				x2 = (x + temp) % p;
				if(x1 < 0)
				{
					x1 = x1 + p;
				}
				x2 = (x + temp) % p;
				alpha = 0;
				beta = 0;
				for (i = 1; i < p; ++i)
				{
					if((i- x1)*(i - x1) % p == a && alpha == 0)
					{
						alpha = i;
					}
					if((i- x1)*(i - x1) % p == a && alpha != 0 && alpha != i)	
					{
						beta = i;
					}
				}
				found1 = binary_search(quad_res + 1,quad_res+((p-1)/2),alpha);
				found2 = binary_search(quad_res + 1,quad_res+((p-1)/2),beta);
				if(found2 && found1)
				{
					
				}
				else if (found2 || found1)
				{
					found = 1;
				}
				else
				{
					
				}
				temp = temp<<1;
			}
			if(!found)
			{
				anomaly_found += 1;
			}
			a++;
		}
		if (anomaly_found > 0)
		{
			printf("Not true for this prime. and number of anomalies is %d\n",anomaly_found);
		}
		else
		{
			printf("True for this prime\n");
		}
		printf("Enter new prime p : ");
		scanf("%d",&p);
	}
	return 0;
}