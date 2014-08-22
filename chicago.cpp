#include <bits/stdc++.h>
#define infi 100000000
using namespace std;


template <class T>
class min_heap
{
	vector <T> heap;
	public:
		int size(void){ return heap.size();}
		void heapify(int index)
		{
			int i = index;
			T t;
			int j = heap.size();
			while(i <= j/2 - 1)
			{
				if(heap[i] > heap[2*i])
				{
					t = heap[i];
					heap[i] = heap[2*i];
					heap[2*i] = t; 
					i = 2*i;
				}
				else if (heap[i] > heap[2*i + 1])
				{
					t = heap[i];
					heap[i] = heap[2*i + 1];
					heap[2*i + 1] = t;
					i = 2*i + 1;
				}
				else
				{
					break;
				}
			}
		}
		void insert(T j)
		{
			heap.push_back(j);
			int temp = heap.size() - 1;
			T t;
			while ( temp >0 && heap[temp/2] > heap[temp] )
			{
				t = heap[temp];
				heap[temp] = heap[temp/2];
				heap[temp/2] = t;
				temp = temp/2;
			}
		}
		void modify(int index,T val)
		{
			T temp = heap[index];
			heap[index] = val;
			T t;
			if( val > temp)
			{
				heapify(index);
			}
			else if (val < temp)
			{
				temp = index;
				while ( temp >0 && heap[temp/2] > heap[temp] )
				{
					t = heap[temp];
					heap[temp] = heap[temp/2];
					heap[temp/2] = t;
					temp = temp/2;
				}
			}
		}
		T pop()
		{
			T val = heap[0];
			heap[0] = heap[heap.size() - 1];
			heapify(0);
			heap.pop_back();
			return val;
		}
		bool empty()
		{
			return heap.size() <= 0;
		}
		/*void print()
		{
			int i;
			for (i = 0; i < heap.size(); ++i)
			{
				printf("%d ",heap[i]);
			}
			printf("\n");
		}*/
};



struct vertex_dist
{
	int vertex;
	int dist;
	bool operator<(const vertex_dist& a)
	const
	{
		return dist < a.dist;
	}
	bool operator>(const vertex_dist& a)
	const
	{
		return dist > a.dist;
	}
};



int main()
{
	int n,m,i,p,q,r,v,u,dist_v;
	int cost;
	vertex_dist temp_vertex;
	scanf("%d",&n);
	while(n)
	{
		scanf("%d",&m);
		vector < vector<int> > G(n);
		vector < vertex_dist > all_dist(n);
		min_heap <vertex_dist> PQ;
		for(i=1;i<n;i++)
		{
			all_dist[i].vertex = i;
			all_dist[i].dist = infi;
			PQ.insert(all_dist[i]);
		}

		all_dist[0].vertex = 0;
		all_dist[0].dist = 0;
		PQ.insert(all_dist[0]);

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
			temp_vertex = PQ.pop();
			printf("%d %d\n", temp_vertex.vertex, temp_vertex.dist);
			v = temp_vertex.vertex;
			dist_v = temp_vertex.dist;
			for(i = 0;i< G[v].size;i++)
			{
				u = G[v][i];
				cost = M[make_pair(u,v)];
			}
		}
		scanf("%d",&n);
	}

	return 0;
}