#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long unsigned int p,j,r1,r2,r3;
	long long unsigned int i;
	srand(time(NULL));
	printf("Enter prime p : ");
	scanf("%llu",&p);
	j = (p - 1)/2;
	/*int quad_res[j + 1];
		for (i = 1; i <= j; ++i)
		{
			quad_res[i] = (i*i)%p;
		}*/
		r1 = rand() % j;
		r2 = rand() % j;
		r3 = rand() % j;
		//printf("%d --- %d\n%d --- %d\n%d --- %d\n",r1,quad_res[r1],r2,quad_res[r2],r3,quad_res[r3] );
		printf("%llu --- %llu\n%llu --- %llu\n%llu --- %llu\n",r1,(r1*r1) % p,r2,(r2*r2) % p,r3,(r3*r3) % p );
		//printf("\n");
		/*sort(quad_res + 1,quad_res + j + 1);
		for (i = 1; i <= j; ++i)
		{
			printf("%d ",quad_res[i] );
		}*/
		//printf("\n");
	return 0;
}