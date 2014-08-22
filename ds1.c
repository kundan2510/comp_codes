#include <stdio.h>
int multiple(int n , int * a, int * b){
	int result;
	if (n ==0)
	{
		return result = 0;
	}
	else{
		int m = n / 2;
		int one = multiple(m , a , b);
		int two = multiple(m , a + m , b + m);
		int three = multiple(m , a , b + m) + multiple(m , a + m , b);
		result = (10^n)*one + (10^m)*three + two ;
		return result ;
		
	}
}

main(){
int n ,ans ,i;
scanf("%d" , &n);
int a[n] ,b[n];
for(i = 0 ; i < n ;i ++)
{
	scanf("%d" , &a[i]);
}
for (i = 0; i < n ; ++i)
{
	scanf("%d" , &b[i]);
}

ans = multiple(n , a , b);
printf("%d\n", ans );

}