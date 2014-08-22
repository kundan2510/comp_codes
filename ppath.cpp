#include <bits/stdc++.h>
using namespace std;
int prime[10001];
void generate_prime()
{
	int i=0;
	int j;
	while(i<10001)
	{
		prime[i]=1;
		i++;
	}
	prime[0]=0;
	prime[1]=0;
	i=0;
	while(i<101)
	{
		while (prime[i] == 0)
			i++;
		j=i+1;
		while(j<10001)
		{
			if(j%i == 0)
				prime[j]=0;
			j++;
		}
		i++;
	}

}
int main()
{
	int i,j,num1,num2,found = 0,u,v,t;
	generate_prime();
	set<int> inqueue;
	map<int,int> dist;
	scanf("%d",&t);
	while(t--)
	{
		queue<int> q;
		inqueue.clear();
		dist.clear();
			scanf("%d%d",&num1,&num2);
			q.push(num1);
			inqueue.insert(num1);
			dist[num1] = 0;
			found = 0;
			if(num1 == num2)
			{
				printf("0\n");
			}
			while((!q.empty())&&(!found)&&(num1 != num2))
			{
				//generate numbers from q.pop() and check if it is not in queue compare it with num2 if its not equal then insert it in queue and in set..if the generated number is equal to num2 then return generation
				u = q.front();
				q.pop();
				for(i = 1;i<10;i++)
				{
					v = (u + i * 1000)%10000;
					if(v == num2)
					{
						printf("%d\n",dist[u]+1);
						found = 1;
						break;
					}
					if ( v > 999 && prime[v] &&(inqueue.find(v) == inqueue.end()))
					{
						q.push(v);
						inqueue.insert(v);
						dist[v] =  dist[u] + 1;
					}
					v = (u / 1000)*1000 + ((u % 1000) + i*100)%1000;
					if(v == num2)
					{
						printf("%d\n",dist[u]+1);
						found = 1;
						break;
					}
					if ( v > 999 && prime[v] &&(inqueue.find(v) == inqueue.end()))
					{
						q.push(v);
						inqueue.insert(v);
						dist[v] =  dist[u] + 1;
					}
					v = (u / 100)*100 + ((u % 100) + i*10)%100;
					if(v == num2)
					{
						printf("%d\n",dist[u]+1);
						found = 1;
						break;
					}
					if ( v > 999 && prime[v] &&(inqueue.find(v) == inqueue.end()))
					{
						q.push(v);
						inqueue.insert(v);
						dist[v] =  dist[u] + 1;
					}
					v = (u / 10)*10 + ((u % 10) + i)%10;
					if(v == num2)
					{
						printf("%d\n",dist[u]+1);
						found = 1;
						break;
					}
					if ( v > 999 && prime[v] &&(inqueue.find(v) == inqueue.end()))
					{
						q.push(v);
						inqueue.insert(v);
						dist[v] =  dist[u] + 1;
					}
				}
		
			}
	}
	return 0;
}
