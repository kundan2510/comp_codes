#include <bits/stdc++.h>
int prime[10001];
void generate_prime()
{
	int i=0;
	int j;
	while(i<10001)
	{
		prime[i]=1;
		i++;
	}
	prime[0]=0;
	prime[1]=0;
	i=0;
	while(i<101)
	{
		while (prime[i] == 0)
			i++;
		j=i+1;
		while(j<10001)
		{
			if(j%i == 0)
				prime[j]=0;
			j++;
		}
		i++;
	}

}
int main()
{
	int i,n,a,j,b,k,l,p;
	generate_prime();
	scanf("%d",&n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d",&a,&b);
		if(b<100001)
		{
			for (j = a; j <= b; j++)
			{
				if(prime[j]==1)
					printf("%d\n",j);
			}
		}
		else
		{
			int range[b-a+1];
			for (j = a; j <= b; j++)
			{
				range[j-a] = 1;
			}
			k=0;l=0;
			while(k*k < b)
			{
				while(prime[k]==0)
					k++;
				p=0;
				for (j=a; j<=b; j++)
				{
					if(j%k==0)
						range[p] = 0;
					p++;
				}
				k++;
			}
			for (j = a; j <= b; j++)
			{
				if(range[j-a]==1)
					printf("%d\n",j);
			}
		}
	}
	return 0;
}

