#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n1,n2,i,j,max_xc,max_yc,max_val=0;
	scanf("%d%d",&n1,&n2);
	char a[n1+1];
	char b[n2+1];
	scanf("%s%s",a,b);
	int DP[n1+1][n2+1];
	for(i = 0; i <=n1;i++)
		DP[i][0] = 0;
	for(i = 0; i <=n2;i++)
		DP[0][i] = 0;
	for(i = 1;i<=n1;i++)
	{
		for(j = 1;j<=n2;j++)
		{
			if(a[i-1] == b[j-1])
			{
				DP[i][j] = DP[i-1][j-1] + 1;
			}
			else
			{
				DP[i][j] = 0;
			}
			if(DP[i][j] > max_val)
			{
				max_val = DP[i][j];
				max_xc = i;
				max_yc = j;
			}
		}
	}
	int tempx = max_xc;
	int tempy = max_yc;
	//printf("%d %d",tempx,tempy);
	while(DP[tempx][tempy] > 0)
	{
		tempx--;
		tempy--;
	}
	tempx++;
	tempy++; 
	while(tempx <= max_xc)
	{
		printf("%c",a[tempx-1]);
		tempx++;
	}
	printf("\n");
}
