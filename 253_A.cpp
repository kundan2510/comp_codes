#include <bits/stdc++.h>
int main()
{
	int count[26];
	int distinct = 0,i;
	memset(count,0,sizeof(count));
	char ch;
	ch = getchar();
	while(ch != '}')
	{
		while((ch < 'a' || ch > 'z' ) && ch != '}')
		{
			ch = getchar();
		}
		if(ch != '}')
		{
			count[ch - 'a']++;
			ch = getchar();
		}
		
	}
	
	for(i = 0;i<26;i++)
	{
		if(count[i] >= 1)
		{
			distinct++;
		}
	}
	printf("%d\n",distinct);
	return 0;
}