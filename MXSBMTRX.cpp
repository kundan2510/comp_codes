#include <bits/stdc++.h>
int main()
{
	int t,n,m,i,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int arr[n][m];
		int right[n][m];
		int down[n][m];
		int diag[n][m];
		int final[n][m];
		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < m; ++j)
			{
				scanf("%d",&arr[i][j]);
			}
		}

		for (i = 0; i < n; ++i)
		{
			for (j = 0; j < m; ++j)
			{
				if (j==0)
				{
					right[i][j] = 1;
				}
				else
				{
					if (arr[i][j] > arr[i][j-1])
					{
						right[i][j] = 1 + arr[i][j-1];
					}
					else
					{
						right[i][j] = 1;
					}
				}
				if (i == 0)
				{
					down[i][j] = 1;
				}
				else
				{
					if (arr[i][j] > arr[i-1][j])
					{
						down[i][j] = 1 + down[i-1][j];
					}
					else
					{
						down[i][j] = 1;
					}
				}
				if (i==0 || j==0)
				{
					diag[i][j] == 0;
				}
				else
				{
					if (diag[i-1][j-1] > diag[i][j])
					{
						diag[i][j] = 1;
					}
					else
					{
						diag[i][j] == 0;
					}
				}
			}
			for (i = 0; i < n; ++i)
			{
				for (j = 0; j < m; ++j)
				{
					if (i==0 && j==0 )
					{
						final[i][j] == 1;
					}
					else
					{
						if (diag[i][j] == 0)
						{
							final[i][j] = max(right[i][j],down[i][j]);
						}
						else
						{
							
						}
					}
				}
			}
		}


	}
	return 0;
}