#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j;
	scanf("%d",&n);
	vector< vector<string> > prn;
	vector<string>::iterator it,it2;
	vector<string> temp;
	printf("test1\n");
	prn.assign(n+1,temp);
	printf("test2\n");
	
	printf("test3\n");
	for(i= 1; i <= n;i++)
	{
		printf("sdfgh\n");
		for(j = 0;j<i;j++)
		{
			printf("xyzdd\n");
			for(it = prn[j].begin();it != prn[j].end();it++)
			{
				printf("rhfujg\n");
				for(it2 = prn[i-j-1].begin();it2 != prn[i-j-1].end();it2++)
				{
					printf("value of it is   %s\n",(*it).c_str() );
					prn[i].push_back('('+ (*it) + ')'+ (*it2));
				}
			}
		}
	}
	for(it = prn[n].begin(); it != prn[i].end();it++)
	{
		printf("%s\n",(*it).c_str());
	}
	return 0;
}