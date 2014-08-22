#include <bits/stdc++.h>
using namespace std;
struct node
{
	int x;
	int y;
	bool operator<(node B) const
    	{
		if(x > B.x)
			return false;
		else if ( x < B.x)
			return true;
		else
			return (y < B.y);
	
    	}
	bool operator==(node B) const
	{
		 return(x==B.x)&&(y==B.y);
	}
	bool operator>(node B) const
    	{
		if(x > B.x)
			return true;
		else if ( x < B.x)
			return false;
		else
			return (y > B.y);
	
    	}
};

int main()
{
	int t,n,i,W;
	long long tot_cost,res_cost,cost;
	scanf("%d",&t);
	while(t--)
	{
		tot_cost = 0;
		cost = 0;
		res_cost = 0;
		scanf("%d",&n);
		node input[n];
		for (i = 0; i < n; ++i)
		{
			scanf("%d",&(input[i].x));
		}
		for (i = 0; i < n; ++i)
		{
			scanf("%d",&(input[i].y));
			tot_cost += input[i].y;
		}
		sort(input,input+n);
		i = 0;
		cost = input[0].y;
		while(cost*2 < tot_cost)
		{
			i++;
			cost += input[i].y; 
			
		}
		W = input[i].x;
		for (i = 0; i < n; ++i)
		{
			res_cost += (abs(W - input[i].x)) * input[i].y;
		}
		printf("%lld\n",res_cost);
	}
	return 0;
}