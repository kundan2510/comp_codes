#include <stdio.h>
void swap(int* a,int* b){
	int t;
	t = *a;
	*a = *b;
	*b = t; 
}

int partition(int * a , int n){
	int i , j;
	int key = a[n - 1];
	j = 0, i = 0;
	while( j < n -1){
		if(*(a + j) > key){
			j++;
		}
		else{
			swap( a +j , a + i);
			i = i + 1;
			j++;
		}
	}
	swap(a+j,a+i);
	return i;
}

quicksort( int * a , int n){
	if (n < 2)
	{
		return ;
	}
	int k = partition(a , n);
	quicksort(a , k );
	quicksort(a + k +1 ,n-k-1);
}

int main(void){
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){	
		scanf("%d",&a[i]);
	}

	quicksort(a , n);
	for(i=0;i<n;i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

