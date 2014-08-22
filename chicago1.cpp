#include <bits/stdc++.h>
#define infi 10000000
using namespace std;
struct vertex_dist
{
	int vertex;
	int dist;
};
struct greater1{
  bool operator()(const vertex_dist& a,const vertex_dist& b) const{
    return a.dist > b.dist;
  }
};
int main()
{
	int n,m,i,p,q,r;
	scanf("%d",&n);
	while(n)
	{
		scanf("%d",&m);
		vector < vector<int> > G(n);
		vector < vertex_dist > all_dist(n);
		for(i=0;i<n;i++)
		{
			all_dist[i].vertex = i;
			all_dist[i].dist = infi;
		}
		make_heap(all_dist.begin(),all_dist.end(),greater1());
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
		
		scanf("%d",&n);
	}

	return 0;
}