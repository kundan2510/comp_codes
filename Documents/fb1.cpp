#include <bits/stdc++.h>
using namespace std;
void swap(int* a,int* b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
void heapify(int * a,int i,int n)
{
	if(2*i > n )
	{
		return;
	}
	if( 2*i <= n)
	{
		if(2*i + 1 <= n)
		{
			if(max(*(a+2*i) , *(a+2*i+1)) > *(a+i))
			{
				if(*(a+2*i) > *(a+2*i+1))
				{
					swap(a+2*i,a+i);
					heapify(a,2*i,n);
				}
				else
				{
					swap(a + 2*i + 1,a+i);
					heapify(a,2*i+1,n);
				}
			}
		}
		else
		{
			if(*(a+2*i) > *(a+i))
			{
				swap(a+2*i,a+i);
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int v[n+1];
	int temp,i;
	v[0] = 0;
	for(i = 0;i<n;i++)
	{
		scanf("%d",&temp);
		v[i+1] = abs(temp);
	}
	for(i = n;i>=1;i--)
	{
		heapify(v,i,n);
	}
	for(i = 1;i<=n;i++)
	{
		printf("%d ",v[i]);
	}
	printf("\n");
}
