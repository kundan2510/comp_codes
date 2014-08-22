#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	if(min(m,n) & 1)
	{
		printf("Akshat\n");
	}
	else
	{
		printf("Malvika\n");
	}
	return 0;
}