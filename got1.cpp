#include <stdio.h>
int main()
{
	char ch;
	int i,flag=0;
	int let[26];
	for(i=0;i<26;i++)
	{
		let[i] = 0;
	}
	ch = getchar();
	if (ch == '\n' || ch == EOF)
	{
		ch = getchar();
	}
	while(ch != '\n' || ch != EOF)
	{
		let[ch - 'a']++;
		ch = getchar();
	}
	for(i=0;i<26;i++)
	{
		if (let[i] % 2 ==1)
		{
			flag++;
		}
	}
	if (flag < 2)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}