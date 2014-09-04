#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct edge{
	int v1;
	int v2;
	float w;
	bool operator<(const edge& e) const
	{
		if (w < e.w)
		{
			return true;
		}
		else
			return false;
	}
} E;
typedef struct vertex{
	int parent;
	int rank;
} V;
void make_set(V * vert,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		(vert+i)->parent = i;
		(vert+i)->rank = 1;
	}
}
void height_compression(V * vert,int leaf,int root)
{
	int i = leaf;
	while((vert+i)->parent != i)
	{
		i = (vert+i)->parent;
		(vert+i)->parent = root;
	}
}
int find(V * vert,int index)
{
	int i = index;
	while((vert+i)->parent != i)
	{
		i = (vert+i)->parent;
	}
	height_compression(vert,index,i);
	return i;
}
void Union(V *vert,int ind1,int ind2)
{
	int i = find(vert, ind1);
	int j = find(vert,ind2);
	if((vert+i)->rank < (vert+j)->rank)
	{
		((vert+i)->rank)++;
		(vert+j)->parent = i;
	}
	else
	{
		((vert+j)->rank)++;
		(vert+i)->parent = j;
	}
}
int main()
{
	int n,v1,v2,A_parent,i;
	float w,mst_w = 0;
	scanf("%d",&n);
	V vert[n];
	make_set(vert,n);
	E A[n-1];
	E temp;
	vector < E > e_g;
	vector < E >::iterator it;
	while(scanf("%d%d%f",&v1,&v2,&w) != -1)
	{
		if(v1 > v2)
		{
			v1 = v2 + v1 - (v2=v1); //swapping
		}
		temp.v1 = v1;
		temp.v2 = v2;
		temp.w = w;
		e_g.push_back(temp);
		//printf("%d %d %.2f\n",temp.v1,temp.v2,temp.w);
	}
	sort(e_g.begin(), e_g.end());
	A_parent = 0;
	for(it = e_g.begin();it != e_g.end();it++)
	{
		temp = *it;
		if(find(vert,temp.v1) != find(vert,temp.v2))
		{
			A[A_parent] = temp;
			A_parent++;
			mst_w += temp.w;
			Union(vert,temp.v1,temp.v2);
		}
	}
	printf("%.2f\n",mst_w );
	for (i = 0; i < n-1; ++i)
	{
		printf("%d %d %.2f\n",A[i].v1,A[i].v2,A[i].w );
	}
	return 0;
}