#include <bits/stdc++.h>

using namespace std;

void permutepar(int open, int close, int len, int ind, char str[])
{
	if(close < open || open<0 || close<0)
		return;
	else if(len == 0)
	{	str[ind] = '\0';
		printf("%s\n", str);
	}
	else
	{
		str[ind] = '(';
		permutepar(open-1, close, len-1, ind+1, str);
		str[ind] = ')';
		permutepar(open, close-1, len-1, ind+1, str);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	char str[2*n + 1];
	int open =n, close = n;
	permutepar(open, close, 2*n, 0, str);
	return 0;
}
9