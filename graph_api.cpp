#include <bits/stdc++.h>
using namespace std;
int main()
{
	int V,temp1,temp2,i,j;
	vector<int>::iterator it;
	scanf("%d",&V);
	vector< vector<int> > UG(V);
	scanf("%d",&temp1);
	temp1--;
	while(temp1 >= 0)
	{
		scanf("%d",&temp2);
		temp2--;
		UG[temp1].push_back(temp2);
		UG[temp2].push_back(temp1);
		scanf("%d",&temp1);
		temp1--;
	}
	for (i = 0; i < V; ++i)
	{
		printf("%d -- ",i+1 );
		for (it = UG[i].begin(); it != UG[i].end(); it++)
		{
			printf("%d ",(*it)+1 );
		}
		printf("\n");
	}
	return 0;
}