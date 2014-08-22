#include <stdio.h>
int main()
{
	int p,i;
	printf("Enter prime p : ");
	scanf("%d",&p);
	for(i=1;i<p-i;i++)
	{
		printf("%d ", (i*i)%p);
	}
	return 0;
}