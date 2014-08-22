#include <bits/stdc++.h>
using namespace std;
int partition(unsigned long long *array,unsigned long long size)
{
	unsigned long long * left = array;
	unsigned long long* right = array+size-1;
	unsigned long long temp;
	unsigned long long index = *array;
	while(left<right)
	{
		while( (left<right)&&(*left)< index )
		{
			left++;
		}
		while((left<right)&&(*right)>= index)
		{
			right--;
		}
		
		temp = *left;
		*left = *right;
		*right = temp;
		if((left<right))
		{
		left++;
		right--;
		}
	}
	return left-array;
}
void qsort(unsigned long long * a,unsigned long long n)
{
	
	unsigned long long l,i;
	if(n<=1)
	{
		return;
	}
	l = partition(a,n);
	if(l==0)
	{
		qsort(a+1,n-1);
	}
	else
	{
	qsort(a,l);
	qsort(a+l,n-l);
	}
}
unsigned long long bin_search(unsigned long long * a,unsigned long long length, unsigned long long key)
{
	unsigned long long l,r,mid;
	l = 0; 
	r = length -1;
	if (key < *(a) || key > *(a + r))
	{
		return length + 1;
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
	return length + 1;
}
int main()
{
	int t,j;
	scanf("%d",&t);
	while(t--)
	{
		unsigned long long n,i,temp;
		unsigned long long index;
			scanf("%llu",&n);
			unsigned long long arr[n];
			unsigned long long result[n];
			for(i=0;i<n;i++)
			{
				scanf("%llu",&arr[i]);
			}
			/*for(j=0;j<n;j++)
			{
				printf("%llu\n",arr[j]);
			}*/
			qsort(arr,n);
			/*for(j=0;j<n;j++)
			{
				printf("%llu\n",arr[j]);
			}*/
			result[0] = 0;
			for(i=1;i<n;i++)
			{
				temp = arr[i] / 2;
				index = bin_search (arr,n, temp);
				if(index != n+1)
				{
					if(index == 0)
					{
						result[i] = result[i-1] + 1;
					}
					else if(result[index] == result[index - 1])
					{
						result[i] = result[i-1] + 1;
					}
					else
					{
						result[i] = result[i-1];
					}
				}
				else
				{
					result[i] = result[i-1];
				}
			}
			/*for(j=0;j<n;j++)
			{
				printf("%llu %llu \n",arr[j],result[j]);
			}
			printf("\n");*/
			printf("%llu\n",result[n-1]);
	}
	return 0;
}
