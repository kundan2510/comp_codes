#include <bits/stdc++.h>
using namespace std;
vector< vector<int> > UG;
int V;
vector<int> Vis;
stack <int> S;
void DFS(int v)
{
	Vis[v] = 1;
	vector<int>::iterator it;
	for(it = UG[v].begin(); it != UG[v].end(); it++ )
	{
		if(!Vis[*it])
		{
			DFS(*it);
		}
	}
	S.push(v);
}
int main()
{
	int temp1,temp2,temp3,i,j;
	int R;
	vector<int>::iterator it;
	vector<int> v;
	scanf("%d%d",&V,&R);
	UG.assign(V,v);
	Vis.assign(V,0);
	for(i = 0;i < R;i++)
	{
		scanf("%d%d",&temp1,&temp2);
		temp1--;
		for(j = 0; j < temp2; j++)
		{
			scanf("%d",&temp3);
			temp3--;
			UG[temp3].push_back(temp1);
		}
	}
	for(i = V - 1; i >= 0; i--)
	{
		sort(UG[i].begin(),UG[i].end(), greater<int>() );
	}
	for(i = V - 1; i >= 0; i--)
	{
		if (!Vis[i])
		{
			DFS(i);
		}
	}

	while(!S.empty())
	{
		temp3 = S.top();
		printf("%d ",temp3 + 1);
		S.pop();
	}
	printf("\n");
	return 0;
}