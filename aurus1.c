#include <stdio.h>
#include <math.h>
int getIntegerComplement(int n) {
	
    int j = log2(n) + 1;
    int k = pow(2,j);
    return k - n - 1;

}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",getIntegerComplement(n) );
	return 0;
}