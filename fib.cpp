#include <bits/stdc++.h>
long long int bin_search(long long int * a,long long int length, long long int key)
{
	long long int l,r,mid;
	l = 0; 
	r = length -1;
	if (key < *(a) || key > *(a + r))
	{
		return -1;
	}
	while(l<=r)
	{
		mid = (l +r)/2;
		if(*(a+mid) == key)
		{
			return mid;
		}
		else if(*(a+mid) > key)
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	return -1;
}
int main()
{
	int t;
	long long int query;
	long long int a = 0;
	long long int b = 1;
	long long int temp;
	long long int result[51];
	result[0] = 0;
	result[1] = 1;
	int count=3;
	scanf("%d",&t);
	while(b<10000000001)
	{
		result[count-1] = a+ b;
		temp = b;
		b = a + b;
		a = temp;
		count++;
	}
	while(t--)
	{
		scanf("%lld",&query);
		if(bin_search(result,51,query) == -1)
		{
			printf("IsNotFibo\n");
		}
		else
		{
			printf("IsFebo\n");
		}
	}
	return 0;
}
