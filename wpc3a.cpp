#include <bits/stdc++.h>
int main()
{
	int j,t;
	char ch,ch2;
	
	scanf("%d",&t);
	ch = getchar();
	while(t--)
	{
		char str[100005];
		ch2 = getchar();
		ch = ch2;
		str[0] = ch2;
		int count = 1,palin = 1;
		while(ch2 != '\n')
		{
			ch2 = getchar();
			while(ch == ch2)
			{
				ch2 = getchar();
			}
			if(ch2 != '\n')
			{
				str[count] = ch2;
				count++;
				ch = ch2;
			}
		}
		str[count] ='\0';
		//printf("%s",str);
		for(j = 0; j< (count/2);j++)
		{
			if(str[count - j - 1] != str[j])
			{
				palin = 0;
				break;
			}
		}
		if (palin==0)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
	return 0;
}
