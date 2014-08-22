#include <bits/stdc++.h>
long long return_matrix[2][2];
void mtrix_mult(long long a[2][2],long long b[2][2],long long m)
{
	return_matrix[0][0] = ((a[0][0]*b[0][0])%m + (a[0][1]*b[1][0])%m)%m;
	return_matrix[0][1] = ((a[0][0]*b[0][1])%m + (a[0][1]*b[1][1])%m)%m;
	return_matrix[1][0] = ((a[1][0]*b[0][0])%m + (a[1][1]*b[1][0])%m)%m;
	return_matrix[1][1] = ((a[1][0]*b[0][1])%m + (a[1][1]*b[1][1])%m)%m;
}
long long fibo_mod(long long n,long long m) //calc fib(n) % m
{
	long long mat[2][2] = {{1,1},{1,0}};
	long long temp[2][2]={{1,0},{0,1}};
	long long temp_2[2][2];
	while(n>0)
	{
		if(n&1)
		{
			mtrix_mult(temp,mat,m);
			temp[0][0] = return_matrix[0][0]; 
			temp[0][1] = return_matrix[0][1]; 
			temp[1][0] = return_matrix[1][0]; 
			temp[1][1] = return_matrix[1][1]; 
		}
			mtrix_mult(mat,mat,m);
			mat[0][0] = return_matrix[0][0]; 
			mat[0][1] = return_matrix[0][1]; 
			mat[1][0] = return_matrix[1][0]; 
			mat[1][1] = return_matrix[1][1]; 
			n = n>>1;
	}
	return temp[1][0];

}
int main()
{
	int t;
	long long n_s,n_e,m,ans;
	m = 1000000007;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n_s,&n_e);
		ans = fibo_mod(n_e + 2,m) - fibo_mod(n_s + 1,m);
		ans = (ans + m)%m;
		printf("%lld\n",ans );
	}
	
	return 0;
}