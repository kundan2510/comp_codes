#include <bits/stdc++.h>
using namespace std;
void recursive_print(int * arrc,int * arrdist,int curr,int bit_val,int dist_ind,int *prarr,int dist_count)
{
	//printf("bit_val is %d curr is %d dist_ind is %d\n",bit_val,curr,dist_ind );
	int i;
	if( bit_val == 0)
	{
		if (curr == 0)
		{
			printf("NULL\n");
			return;
		}
		for(i = 0;i<curr;i++)
		{
			printf("%d ",*(prarr+i) );
		}
		printf("\n");
		return;
	}
	else if(bit_val & 1)
	{
		for (i = 0; i < *(arrc + dist_ind); ++i)
		{
			*(prarr + curr+i) = *(arrdist + dist_ind);
			recursive_print(arrc,arrdist,curr+i+1,bit_val>>1,dist_ind+1,prarr,dist_count);
		}
	}
	else
	{
		recursive_print(arrc,arrdist,curr,bit_val>>1,dist_ind+1,prarr,dist_count);
	}
}
int main()
{
	int n,count,temp,i,tempc;
	scanf("%d",&n);
	int array[n];
	int prarr[n];
	for(i = 0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	sort(array,array+n);
	count = 1;
	for(i = 1;i<n;i++)
	{
		if(array[i-1] != array[i])
			count++;
	}
	int arrdist[count];
	int arrc[count];
	arrdist[0] = array[0];
	temp = 1;
	tempc = 1;
	for(i = 1;i<n;i++)
	{
		if(array[i-1] != array[i])
		{	
			arrdist[temp] = array[i];
			arrc[temp - 1] = tempc; 
			temp++;
			tempc = 1;
		}
		else
		{
			tempc++;
		}
	}
	arrc[count-1] = tempc;
	/*printf("original arrya is :\n");
	for(i = 0;i< n; i++)
	{
		printf("%d ",array[i] );
	}
	printf("\ndistinc array with count is :\n");
	for(i = 0;i< count; i++)
	{
		printf("%d ",arrdist[i] );
	}
	printf("\n");
	for(i = 0;i< count; i++)
	{
		printf("%d ",arrc[i] );
	}
	printf("\n");*/
	for(i = 0;i< (1<<(count));i++)
	{
		recursive_print(arrc,arrdist,0,i,0,prarr,count);
	}
	return 0;
}
