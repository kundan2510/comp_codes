#include <stdio.h>
using namespace std;
void print_result(int m, int n)
{
	printf("%d %d\n",m,n);
	if(m>n)
		print_result(m-n,n);
	else if(m<n)
	{
		print_result(m,n-m);
	}
}
int check_validity(int x,int y,int m,int n)
{
	int temp;
	if(x == m && y == n)
	{
		print_result(m,n);
		return 1;
	}
	else if(x > m || y > n)
	{
		return -1;
	}
	else
	{
		 temp = check_validity(x,x+y,m,n);
		 if(temp == -1)
		 	return check_validity(x+y,y,m,n);
		 else
		 	return temp;
	}	
}
int main()
{
	int m, n,t;
	scanf("%d%d",&m,&n);
	t = check_validity(1,1,m,n);
	if(t == -1)
		printf("not possible\n");
}
