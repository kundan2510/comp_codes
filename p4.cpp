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

int main()
{
	int i,temp,j,p,k,curr_count,found,prev = -1,rowchange = 0,start,end;
	scanf("%d%d%d",&i,&j,&p);
	start = 1;
	end = j;
	struct node A[p];
	struct node curr, prev_node;
	prev_node.x = -1;
	prev_node.y = -1;
	for(k =0 ; k<p ; k++)
	{
		scanf("%d%d",&A[k].x,&A[k].y );
	}
	sort(A,A+p);
	curr = A[0];
	temp = 1;
	found = 0;
	curr_count = 1;
	while(temp < A[0].x && temp <= i)
	{
		printf("%d\n",end - start);
		temp++;
	}
	for(k = 1; k < p;k++)
	{
		if( curr == A[k] )
		{
			curr_count++;	
		}
		else
		{
			rowchange = 0;
			if(prev > 1)
			{
				if(curr.y != prev_node.y + 1)
				{
					found = 1;
				}
				else if (curr_count < prev - 1)
				{
					found = 1;
				}
			}
			
			if(curr.y == 1)
			{
				start = curr_count + 1;
			}
			if(curr.y == j)
			{
				end = j + curr_count;
			}
			if(curr.x < A[k].x)
			{
				rowchange = 1;
				if( found ||(prev <= 1 && curr_count > 1 && curr.y != j))
				{
					printf("-1\n");
					found = 0;
				}
				else
				{
					printf("%d\n", end - start);
				}
				start = 1;
				end = j;
				temp = curr.x + 1;
				while(temp < A[k].x)
				{
					printf("%d\n",end - start);
					temp++;
				}
				prev = -1;
				curr_count = 1;
				prev_node.x = -1;
				prev_node.y = -1;
			}
			if(rowchange == 0)
			{
				prev_node = curr;
				prev = curr_count;
				curr_count = 1;
			}
			curr = A[k];
		}

	}
//	printf("curr = %d prev=%d\n",curr_count,prev);	
//	curr = A[p-1];
			if(prev > 1)
			{
				if(curr.y != prev_node.y + 1)
				{
					found = 1;
				}
				else if (curr_count < prev - 1)
				{
					found = 1;
				}
			}
			
			if(curr.y == 1)
			{
				start = curr_count + 1;
			}
			if(curr.y == j)
			{
				end = j + curr_count;
			}
				if( found ||(prev <= 1 && curr_count > 1 && curr.y != j))
				{
					printf("-1\n");
					found = 0;
				}
				else
				{
					printf("%d\n", end - start);
				}
				start = 1;
				end = j;
/*	printf("curr is %d %d\nincrement positions are:\n",curr.x,curr.y);
	for(k=0;k<p;k++)
		printf("%d %d\n",A[k].x,A[k].y);
*/
	temp = curr.x + 1;
	while(temp <= i)
	{
		printf("%d\n",end-start);
		temp++;
	}
	return 0;
}
