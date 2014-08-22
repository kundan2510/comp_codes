#include <bits/stdc++.h>
#define infi 100000000
using namespace std;
typedef struct vertex_dist
{
	int vertex;
	int dist;
} *vertex_dist_p;

struct my_minheap_comp {

    bool operator()(vertex_dist_p a, vertex_dist_p b)
    {
       return a->dist > b->dist;
    }
};

int main()
{
	int n,m,i,p,q,r,v,u,dist_v;
	int cost;
	vertex_dist_p temp_vertex;
	scanf("%d",&n);
	while(n)
	{
		scanf("%d",&m);
		vector < vector<int> > G(n);
		vector < vertex_dist > all_dist(n);
		priority_queue <vertex_dist_p, vector <vertex_dist_p>, my_minheap_comp> PQ;
		for(i=1;i<n;i++)
		{
			all_dist[i].vertex = i;
			all_dist[i].dist = infi;
			PQ.push(&all_dist[i]);
		}

		all_dist[0].vertex = 0;
		all_dist[0].dist = 0;
		PQ.push(&all_dist[0]);

		map < pair <int,int>,int > M;
		for(i = 0;i<m;i++)
		{
			scanf("%d%d%d",&p,&q,&r);
			p--;
			q--;
			G[p].push_back(q);
			G[q].push_back(p);
			M[make_pair(p,q)] = r;
			M[make_pair(q,p)] = r;
		}

		while(!PQ.empty())
		{
			temp_vertex = PQ.top();
			//printf("%d %d\n", temp_vertex->vertex, temp_vertex->dist);
			v = temp_vertex->vertex;
			dist_v = temp_vertex->dist;
			for(i = 0;i< G[v].size;i++)
			{
				u = G[v][i];
				cost = M[make_pair(u,v)];
			}
			PQ.pop();
		}
		scanf("%d",&n);
	}

	return 0;
}