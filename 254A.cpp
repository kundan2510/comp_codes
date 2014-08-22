#include <bits/stdc++.h>
int main()
{
	int n,m;
	scanf("%d",&n,&m);
	char chess[n][m];
	char chess_output[n][m];
	for(i = 0; i<n;i++)
	{
		for (j = 0; j < m; ++j)
		{
			scanf("%c",&chess[i][j]);
		}
	}
	return 0;
}