#include <stdio.h>
int main()
{
	int count,i;
	char arr[500];
	char ch = 'a';/*
	printf("%d\n",ch);
	printf("%d\n",4&3);
	printf("%d\n",4|3);
	printf("%d\n",5 & 3);
	while(ch > 0)
	{
		count += ch & 1;
		ch >>= 1;
	}
	printf("%d\n",count);*/	
	scanf("%s",arr);
	for(i = 0; i < 10;i++)
	{
		printf("current character is : %c\n", arr[i]);
	}
	printf("%s",arr);
	arr[7] = '\0';
	printf("%s",arr);
	return 0;
}
