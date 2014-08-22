#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,j,result;
	scanf("%d",&t);
	while(t--)
	{
		long long n,i,temp;
		long long index;
			scanf("%lld",&n);
			long long arr[n];
			result = 0;
			bool status[n];

			memset(status,0,sizeof(status));

			for(i=0;i<n;i++)
			{
				scanf("%llu",&arr[i]);
			}
			/*for(j=0;j<n;j++)
			{
				printf("%llu\n",arr[j]);
			}*/
			sort(arr,arr+n);
			/*for(j=0;j<n;j++)
			{
				printf("%llu\n",arr[j]);
			}*/
			//result[0] = 0;
			for(i=n; i > 0; i--)
			{
			     if(!status[i-1])
			     {
					temp = arr[i-1] / 2;
					index = lower_bound(arr,arr+ i, temp) - arr;
					if(index != i && arr[index] == temp && !status[index])
					{
						result++;
						status[index] = true;
						if(index == 0)
						{
							arr[index] = -10000;
						}
						else
						{
							arr[index] = arr[index-1];
						}
					}
					status[i-1] = true;
				}
			}
			printf("%d\n",result);
	}
	return 0;
}