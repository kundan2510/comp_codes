#include <bits/stdc++.h>
using namespace std;
char prnth[100];
void valid_paren(int i , int j)
{
	int k;
	if(j<= i)
		return;
	prnth[i] = '(';
	for(k = i+1;k<j;k=k+2)
	{
		prnth[k] = ')';
		valid_paren(i+1,k);
		valid_paren(k+1,j);
		printf("%s\n",prnth);
	}
}
int main()
{
	int n,i;
	scanf("%d",&n);
	prnth[2*n] = '\0';
	valid_paren(0,2*n-1);
}
