#include<stdio.h>
main()
{
	int i, j, q, p, k, n = 100;
	int a[101];
																
	for	(i = 0;i < 101;i = i+1)
	{
		a[i]=1;
	}			
	for (j = 2; j < 101; j = j+1)
	{
		if (a[j] == 1)
		{
			for (p = 0 ; p < 101; p = p+1)
			{
					q = j*j + p*j;	
					if (q < 101)
					{
						a[q] = 0;
					}
					
			}									 		
		}										 	
	}																	 
	for (k = 2; k < 101; k = k+1)
	{
			if (a[k] == 1)
			{
				printf("%d ", k );															
			}															
	}																
}
