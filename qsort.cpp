#include <stdio.h>
int partition(int *array,int size)
{
	int * left = array;
	int* right = array+size-1;
	int temp;
	int index = *array;
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
void qsort(int * a,int n)
{
	
	int l,i;
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
int bin_search(int * a,int length, int key)
{
	int l,r,mid;
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
main()
{
	int n,i,temp;
	scanf("%d",&n);
	int array[n];
	int *a = array;
	for(i =0;i<n;i++)
	{
		scanf("%d",&(array[i]));
	}
	qsort(a,n);
	for(i =0;i<n;i++)
	{
		printf("%d ", array[i]);
	}
	printf("\nEnter search key:  ");
	while(scanf("%d",&temp))
	{
		printf("Index is %d\n", bin_search(array, n, temp));
		printf("Enter search key:  ");
	}
}
