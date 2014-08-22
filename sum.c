#include<stdio.h>
main(){
	int n, i, j, k, sum, max;
	int a[30];
	sum = 0;
	max = sum;
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	i = 0;
	while( i < n )
	{
		for (j = i + 1; j < n; j = j +1)
		{
			for (k = i; k <= j; k=k+1)
		     	{
		     		sum = sum + a[k];
		     	}
		     	printf("%d\n", sum);
		     	if (sum > max)
		     	{
		     		max = sum;
		     		sum = 0;
		     	}
		     	sum = 0;
        }
        sum = 0;
     	i = i +1;
	}
	printf("%d\n", max);
}
