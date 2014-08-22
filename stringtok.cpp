#include <bits/stdc++.h>
using namespace std;
int main()
{
	char temp[10];
	char * hour;
	char * min;
	char * sec;
	scanf("%s",temp);
	hour = strtok(temp,":");
	min = strtok(NULL,":");
	sec = strtok(NULL,":");
	printf("%s\n%s\n%s\n",hour,min,sec );
	return 0;
}