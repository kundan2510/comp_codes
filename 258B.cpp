#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,np=0,fx=-1,sx=-1;
	int curr,next;
	scanf("%d",&n);
	int array[n];
	for (i = 0; i < n; ++i)
	{
		scanf("%d",&array[i]);
	}
	for (i = 0; i < n-1; ++i)
	{
		curr = array[i];
		next = array[i+1];
		if(fx == -1)
		{
			if(min(curr,next) == next)
			{
				fx = i;
			}
		}
		else
		{
			if(sx == -1)
			{
				if(min(curr,next) == curr)
				{
					sx = i;
				}
			}
			else
			{
				if(min(curr,next) == next)
				{
					np = 1;
				}
			}
		}
		if(np == 1)
		{
			break;
		}
	}
	if(np == 1)
	{
		printf("no\n");
	}
	else
	{
		if(fx == -1)
		{
			printf("yes\n1 1\n");
		}
		else if(fx == 0)
		{
			if(sx == -1)
			{
				printf("yes\n1 %d\n",n);
			}
			else if(array[sx+1] > array[fx])
			{
				printf("yes\n1 %d\n",sx+1);
			}
			else
			{
				printf("no\n");
			}
		}
		else
		{
			if(sx == -1)
			{
				if(array[n-1] > array[fx - 1])
				{
					printf("yes\n%d %d\n",fx+1,n);
				}
				else
				{
					printf("no\n");
				}
				
			}
			else
			{
				if((array[sx] > array[fx - 1]) && (array[fx] < array[sx + 1]))
				{
					printf("yes\n%d %d\n",fx+1,sx+1 );
				}
				else
				{
					printf("no\n");
				}
			}
		}
			
	}
	return 0;
}