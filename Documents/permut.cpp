#include <bits/stdc++.h>
using namespace std;
void swap (char * a, char * b)
{
	char t;
	t = *a;
	*a = *b;
	*b = t;	
}
int search(char * arr,int i,int j,char c)
{
	for(;i<=j;i++)
	{
		if(*(arr+i) == c)
			return 1;
	}
	return 0;
}
void permut(int s, int l,char * arr)
{
	int i;
	if(s == l)
	{
		printf("%s\n",arr);
	}
	else
	{
		//printf("%d %d %s\n",s,l,arr);
		permut(s+1,l,arr);
		for(i = s+1; i <= l ; i++)
		{
			if(!search(arr,s,i-1,*(arr+i)))
			{
				swap( arr + s,arr + i);
				permut(s+1,l,arr);
				swap(arr + s, arr + i);
			}
		}
	}
}
int main()
{
	int n,i;
	scanf("%d",&n);
	char arr[n+1];
	scanf("%s",arr);
	permut(0,n-1,arr);
	return 0;
}
