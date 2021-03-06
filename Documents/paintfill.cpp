#include <bits/stdc++.h>
using namespace std;
vector < vector<int> > G;
vector < vector<int> > visited;
void negfil(int x,int y,int n, int negb[][2])
{
	int i;
	negb[0][0] = x; negb[0][1] = y + 1;
	negb[1][0] = x+1; negb[1][1] = y + 1;
	negb[2][0] = x-1; negb[2][1] = y + 1;
	negb[3][0] = x; negb[3][1] = y-1;
	negb[4][0] = x+1; negb[4][1] = y - 1;
	negb[5][0] = x-1; negb[5][1] = y - 1;
	negb[6][0] = x+1; negb[6][1] = y ;
	negb[7][0] = x-1; negb[7][1] = y ;
	for(i =0;i<8;i++)
	{
		if(negb[i][0] >= n || negb[i][1] >= n || negb[i][0] < 0 || negb[i][1] < 0)
		{
			negb[i][0] = -1;
		}
	}
}
void DFS(int x,int y,int c,int n,int negb[][2],int orig)
{
	//printf("asdgf");
	visited[x][y] = 1;
	int i;
	G[x][y] = c;
	negfil(x,y,n,negb);
	int array[8][8];
	for(i = 0;i<n;i++)
	{
		for(j = 0;j<n;j++)
		{
			array[i][j] = negfil[i][j];
		}
		printf("\n");
	}
	for(i =0;i<8;i++)
	{
		printf("checking for neghbour %d %d\n",negb[i][0],negb[i][1],visited[negb[i][0] ][negb[i][1] ]);
		if(negb[i][0] != -1 && !visited[negb[i][0] ][negb[i][1] ] && G[negb[i][0] ][negb[i][1] ] == orig)
		{
			printf("going into dfs for %d %d\n",negb[i][0],negb[i][1]);
			DFS(negb[i][0],negb[i][1],c,n,negb,orig);
		}
	}
}
int main()
{
	int n, x, y,i, j,temp,c,orig;
	scanf("%d%d%d%d",&n,&x,&y,&c);
	vector <int> g;
	G.assign(n,g);
	g.assign(n,0);
	visited.assign(n,g);
	int negb[8][2];
	for(i = 0;i<n;i++)
	{
		//printf("row %d starts\n",i);
		for(j = 0;j<n;j++)
		{
			scanf("%d",&temp);
			G[i].push_back(temp);
			//printf("%d\n",G[i][j]);
		}
		//printf("row %d ended\n",i);
	}
	//scanf("%d",&temp);
	//printf("%d\n",temp);
	printf("\n");
	orig = G[x][y];
	DFS(x,y,c,n,negb,orig);
	for(i = 0;i<n;i++)
	{
		for(j = 0;j<n;j++)
		{
			printf("%d ",G[i][j]);
		}
		printf("\n");
	}
}

