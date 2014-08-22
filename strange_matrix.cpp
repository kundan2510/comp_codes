#include<bits/stdc++.h>
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
struct node_count
{
	struct node n;
	int count;
};

int main()
{
	int i,temp,j,p,k,s,curr_count,found,prev = -1,rowchange = 0,start,end;
	scanf("%d%d%d",&i,&j,&p);
	start = 1;
	end = j;
	
	struct node A[p];
	struct node curr, prev_node,pprev_node;
	struct node_count temp_node_count;
	vector <struct node_count> freq;
	vector<struct node_count>::iterator it;
	prev_node.x = -1;
	prev_node.y = -1;
	for(k =0 ; k<p ; k++)
	{
		scanf("%d%d",&(A[k].x),&(A[k].y) );
	}
	sort(A,A+p);
	temp = 1;
	found = 0;
	end = j;
	start = 1;
	while(temp < (A[0]).x && temp <= i)
	{
		printf("%d\n",end - start);
		temp++;
	}
	
	for(k = 0; k < p;k++)
	{
		curr = A[k];
		if(freq.empty() || !((freq.back()).n == curr))
		{
			temp_node_count.n = curr;
			temp_node_count.count = 1;
			freq.push_back(temp_node_count);
		}
		else 
		{
			((freq.back()).count)++;
		}
	}
	/*while(!freq.empty())
	{
		printf("Entry %d %d with count = %d.\n",((freq.back()).n).x, ((freq.back()).n).y,freq.back().count);
	}*/
		prev_node = freq.begin() -> n;
		if(prev_node.y == 1)
		{
			start = freq.begin()->count + 1;
		}
		if(prev_node.y == j)
		{
			end = j + freq.begin()->count;
		}
		for(it = freq.begin()+1;it != freq.end();it++)
		{
			curr  = it->n;
			if(curr.x > prev_node.x)
			{
				if(prev_node.y == j)
				{
					end = j + (it - 1)->count;
				}

				if(found == 1)
				{
					printf("-1\n");
				}
				else if(prev_node.y != j)
				{
					if((it - 1)->count > 1)
					{
						printf("-1\n");
					}
					else
					{
						printf("%d\n",end - start);
					}
				}
				else
				{
					printf("%d\n",end - start);
				}
				temp = prev_node.x + 1;
				start = 1;
				end = j;
				while(temp < curr.x && temp <= i)
				{
					printf("%d\n",end - start);
					temp++;
				}

				if(curr.y == 1)
				{
					start = 1 + it->count;
				}
				else
				{
					start = 1;
				}
				end = j;
				found = 0;
			}
			else
			{
				if((it-1)->count > 1 )
				{
					if(curr.y != prev_node.y + 1)
					{
						found = 1;
					}
					else
					{
						if((it->count) < (it - 1)->count - 1)
						{
							found = 1;
						}
					}
				}
			}
			prev_node = curr;
		}
		if(prev_node.y == j)
		{
			end = j + (it - 1)->count;
		}

		if(found == 1)
		{
			printf("-1\n");
		}
		else if(prev_node.y != j)
		{
			if((it - 1)->count > 1)
			{
				printf("-1\n");
			}
			else
			{
				printf("%d\n",end - start);
			}
		}
		else
		{
			printf("%d\n",end - start);
		}
		start = 1;
		end = j;
		temp = A[p-1].x + 1;
		while(temp <= i)
		{
			printf("%d\n",end - start);
			temp++;
		}
	return 0;
}
