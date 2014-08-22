#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,i,interval,h,m,s,k,res,j,num;
	scanf("%d",&t);
	char temp[11];
	char * hour;
	char * min;
	char * sec;
	for (k = 0; k < t; ++k)
	{
		scanf("%d",&n);
		if (n == 0)
		{
			scanf("%d",&interval);
			printf("Case %d: 0\n",k+1);
			continue;
		}
		int time_input[n];
		for (i = 0; i < n; ++i)
		{
			scanf("%s",temp);
			hour = strtok(temp,":");
			min = strtok(NULL,":");
			sec = strtok(NULL,":");
			h = atoi(hour);
			m = atoi(min);
			s = atoi(sec);

			time_input[i] = 3600*h + 60*m + s;
		}
		scanf("%d",&interval);
		sort(time_input,time_input+n);
		i = 0;
		res = 0;
		num = 0;
		j = 0;
		while(j < n && i < n)
		{
			if(time_input[i] + interval > time_input[j])
			{
				num++;
				j++;
			}
			else
			{
				i++;
				num--;
			}
			res = max(res,num);
		}
		printf("Case %d: %d\n",k+1,res);
	}

	return 0;
}