#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 1000000000
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
void make_set(int * vertex,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		*(vertex+i) = i;
	}
}
int find(int * vertex,int index)
{
	int i = index;
	while(*(vertex+i) != i)
	{
		i = *(vertex+i);
	}
	return i;
}
void Union(int *vertex,int ind1,int ind2)
{
	int i = find(vertex, ind1);
	int j = find(vertex,ind2);
	*(vertex + i) = j;
}
int main()
{
	int n,v1,v2,A_index,i;
	float w,mst_w = 0;
	scanf("%d",&n);
	int vertex[n];
	make_set(vertex,n);
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
	A_index = 0;
	for(it = e_g.begin();it != e_g.end();it++)
	{
		temp = *it;
		if(find(vertex,temp.v1) != find(vertex,temp.v2))
		{
			A[A_index] = temp;
			A_index++;
			mst_w += temp.w;
			Union(vertex,temp.v1,temp.v2);
		}
	}
	printf("%.2f\n",mst_w );
	for (i = 0; i < n-1; ++i)
	{
		printf("%d %d %.2f\n",A[i].v1,A[i].v2,A[i].w );
	}
	return 0;
}