#include <bits/stdc++.h>
using namespace std;
string DP[105][105];
char A[105], B[105];
int main()
{
	int i,j;
	string a,b,res,temp;
	while(scanf("%s",A) != -1)
	{
		scanf("%s",B);
		a = A;
		b = B;
		DP[0][0] = "";
		for(i = 1;i< a.length()+1;i++)
		{
			DP[i][0] =DP[i-1][0] + A[i-1];
		}
		for (j = 1; j < b.length()+1; j++)
		{
			DP[0][j] = DP[0][j-1] + B[j-1];
		}
		for (i = 1; i < a.length()+1; ++i)
		{
			for(j=1;j<b.length()+1;j++)
			{
				if(A[i-1] == B[j-1])
				{
					if(i == 1 && j == 1)
					{
						DP[i][j] = A[i-1];
					}
					else
					{
						DP[i][j] = DP[i-1][j-1] + A[i-1];
					}
					
				}
				else
				{
					if(DP[i-1][j].length() < DP[i][j-1].length())
					{
						DP[i][j] = DP[i-1][j] + A[i-1];
					}
					else
					{
						DP[i][j] = DP[i][j-1] + B[j-1];	
					}
				}
				
			}
		}
		printf("%s\n",DP[a.length() ][b.length()].data() );
	}
	return 0;
}