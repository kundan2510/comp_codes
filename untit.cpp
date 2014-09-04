#include <stdio.h>
int main()
{
	int n, i, j, k, l, piv, r=0;    //piv for special use of pivot
	printf("Enter the order ");
	scanf("%d", &n);
	
	float a[n][n+1];
	
	printf("enter the matrix \n");
	//printf("%d", n);
	//input of matrix
	for(i=0; i<n; i++)
		{for(j=0; j<n+1; j++)
			{scanf("%f", &a[i][j]);
			//printf("line %d th",i);
			
			}
		}
/*		for(i=0; i<n; i++)
	{
		for(j=0; j<n+1; j++)
		{
			printf("%f ", a[i][j]);
		}
		printf("\n");
	}
*/	
	//Gauss Elimination
	for(j=0; j<n-1; j++)
	{
		/*for(i=n-1; i>j; i--)
		{
			for(k=0; k<n-j && r!=1; k++)     //check for singular or zero pivot
			{
				if (a[j+k][j]==0) ;
				else 
				{
				r=1; k=k-1;
				}
				
			}
			
			if(r==0) {
					printf("singular matrix- no solution"); return 0;
				}
			else                                // for zero pivot swap
			{
				float b[n+1];
				for (l=0;l<n+1; l++)
				{
					b[l]= a[j+k][l];
					a[j+k][l]= a[j][l];
					a[j][l]= b[l];
					
				}
			}
			
		  */    
		  i = 1;j=0;                      // use gauss algorithm
			for(l=0;l<n+1; l++)
			{
				printf("i = %d, j = %d, l = %d\n ",i,j,l);
				//a[i][l] = a[i][l] -( a[j][l]*(a[i][j]/a[j][j]));
				a[i][j] = i+j;
			}
		
	
		//}
	}
	//for printing guass matrix
			for(i=0; i<n; i++)
			{
				for(j=0; j<n+1; j++)
				{
					printf("%f ", a[i][j]);
					
				}
				printf("\n");
			}
	
/*	//backword substitution
	float x[n];
	float sum=0.0;       // sum for summation of ai*xi
	for(i=n-1;i>=0; i--)
	{
				
		x[i]=(a[i][n]-sum)/a[i][i];
		
		for (j=n-1; j>i; j--)
		{
			sum= sum+a[i-1][j]*x[j];
		}
	
	}
	
	// printing output
	for(i=0; i<n;i++)
	{
		printf("%f\n", x[i]);
	}
	*/
}
