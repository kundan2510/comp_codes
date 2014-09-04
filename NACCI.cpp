#include <bits/stdc++.h>
using namespace std;
int N;
int req_mem[30][30];
void fill_req_mem()
{
	int i,j;
	for(i = 0;i<30;i++)
	{
		req_mem[0][i] = 1;
	}
	for(i = 1;i<30;i++)
	{
		for(j = 0;j<30;j++)
		{
			if(i == j+1)
			{
				req_mem[i][j] = 1;
			}
			else
			{
				req_mem[i][j] = 0;
			}
		}
		
	}
}
int result(int k, int l)
{

}
int main()
{
	int n,k,l;
	scanf("%d%d%d",&n,&k,&l);
	N = n;

	return 0;
}