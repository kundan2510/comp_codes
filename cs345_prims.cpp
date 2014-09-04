#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 100000000
using namespace std;
int N;
typedef struct edge{
	int v1;
	int v2;
	double w;
	bool operator<(const edge& e) const
	{
		return (w < e.w);
	}
	bool operator>(const edge& e) const
	{
		return (w > e.w);
	}
	bool operator==(const edge& e) const
	{
		return (w == e.w);
	}
} E;

typedef struct edge_entry{
	int v2;
	double w;
	bool operator<(const edge_entry& e) const
	{
		return (w < e.w);
	}
	bool operator>(const edge_entry& e) const
	{
		return (w > e.w);
	}
	bool operator==(const edge_entry& e) const
	{
		return (w == e.w);
	}
} EN;

typedef struct vertex{
	double key;
	int index;
	E eg;
	bool operator<(const vertex& ver) const
	{
		return (key < ver.key);
	}
	bool operator>(const vertex& ver) const
	{
		return (key > ver.key);
	}
	bool operator==(const vertex& ver) const
	{
		return (key == ver.key);
	}
} V;

class Heap
{
	public:
		V * contnr;
		int size;
		int * vert_location;
		Heap(V * cntr,int * vert_loc);
		void Insert(V v);
		void Decrease_key(V v, double key, E eg);
		V ExtractMin();
		void print();
	private:
		void Heapify(int i);
		void swap(V * ptr1, V * ptr2);
};
void
Heap::swap(V * ptr1, V * ptr2)
{
	int i = ptr1 - contnr;
	int j = ptr2 - contnr;
	*(vert_location + ptr1->index) = j;
	*(vert_location + ptr2->index) = i;
	V temp;
	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
} 

Heap::Heap(V * cntr, int * vert_loc)
{
	contnr = cntr;
	vert_location = vert_loc;
	size = 0;
}

void 
Heap::print()
{
	int i;
	printf("size = %d\n",size );
	printf("location array :  \n");
	for(i = 0 ; i< N;i++)
	{
		printf("%d is at %d in heap\n",i,*(vert_location+i) );
	}
	printf("heap with index:\n");
	for(i = 0 ; i< size;i++)
	{
		printf("at position %d, vertex is %d with eg (%d, %d) and w %.2f\n",i,(contnr + i)->index,((contnr+i)->eg).v1,((contnr+i)->eg).v2,(contnr + i)->key );
	}
}
void
Heap::Heapify(int i)
{
	while(i < size/2)
	{
		if(*(contnr + i) > min(*(contnr + 2*i + 1) , *(contnr + 2*i + 2)))
		{
			if(*(contnr + 2*i + 1) < *(contnr + 2*i + 2))
			{
				swap(contnr + i,contnr + 2*i + 1);
				/*temp = *(vert_location + i);
				*(vert_location + i) = *(vert_location + 2*i + 1);
				*(vert_location + 2*i + 1) = temp;*/
				i = 2*i + 1;
			}
			else
			{
				swap(contnr + i,contnr + 2*i + 2);
				/*temp = *(vert_location + i);
				*(vert_location + i) = *(vert_location + 2*i + 2);
				*(vert_location + 2*i + 2) = temp;*/
				i = 2*i + 2;
			}
		}
		else
		{
			break;
		}
	}
}
void
Heap::Insert(V vert)
{
	int i = size;
	*(vert_location + vert.index) = size;
	*(contnr + i) = vert;
	size++;
	while(i > 0 && *(contnr + i) < *(contnr + (i-1)/2))
	{
		swap(contnr + i, contnr + (i-1)/2);
		/**(vert_location + i) = (i-1)/2;
		*(vert_location + (i-1)/2) = i;*/
		i = (i-1)/2;
	} 
}

V Heap::ExtractMin()
{
	V ret_vert = *contnr;
	contnr->key = INF;
	swap(contnr,contnr+size-1);
	int i = 0;
	Heapify(i);
	size--;
	return ret_vert;
}
void Heap::Decrease_key(V v,double dk, E eg)
{
	//printf("*******************************Just before decrease key\n");
	//print();
	int i = *(vert_location + v.index);
	(contnr + i)->key = dk;
	(contnr+i)->eg = eg;
	while(i > 0 && *(contnr + i) < *(contnr + (i-1)/2))
	{
		swap(contnr + i, contnr + (i-1)/2);
		/**(vert_location + i) = (i-1)/2;
		*(vert_location + (i-1)/2) = i;*/
		i = (i-1)/2;
	} 
	//printf("********just after decrease key\n");
	//print();
	//printf("*********************************************\n");

}
int main()
{
	int n,i,tot_in = 0,v1,v2,currver,temp_int;
	double w;
	scanf("%d",&n);
	N = n;
	V vert_arr[n];
	bool in_heap[n];
	int arr_point_vert[n];
	bool in_mst[n];
	E answer[n-1];
	Heap H = Heap(vert_arr,arr_point_vert);
	vector< EN > adjacency[n];
	vector< EN >::iterator it;
	EN tempen;
	V tempv;
	E tempeg;
	for(i = 0;i<n;i++)
	{
		arr_point_vert[i] = i;
		in_mst[i] = false;
		in_heap[i] = false;
		vert_arr[i].key = INF;
		vert_arr[i].index = i;
	}
	while(scanf("%d%d%lf",&v1,&v2,&w) != -1)
	{
		tempen.w = w;
		tempen.v2 = v2;
		adjacency[v1].push_back(tempen);
		tempen.v2 = v1;
		adjacency[v2].push_back(tempen);
		//printf("%d %d %.2f\n",temp.v1,temp.v2,temp.w);
	}

	in_heap[0] = true;
	H.Insert(vert_arr[0]);
	while(tot_in < n)
	{
		tempv = H.ExtractMin();
		tot_in++;
		if(tot_in >= 2)
		{
			//printf("**extracted element %d %d %d %lf\n",tempv.index,(tempv.eg).v1, (tempv.eg).v2, (tempv.eg).w );
			answer[tot_in-2] = tempv.eg;
		}
		currver = tempv.index;
		in_mst[currver] = true;
		for(it = adjacency[currver].begin(); it != adjacency[currver].end() ; it++)
		{
			tempen = *it;
			i = tempen.v2;
		//	printf("***temporary adj vertex is %d with weight %lf\n",i, tempen.w );
			if(! in_mst[i])
			{
				if(! in_heap[tempen.v2])
				{
					//printf("****going to insert %d %d %lf\n",currver,tempen.v2, tempen.w );
					tempeg.v1 = currver;
					tempeg.v2 = i;
					tempeg.w = tempen.w;
					tempv.eg = tempeg;
					tempv.key = tempeg.w;
					tempv.index = i;
					H.Insert(tempv);
					in_heap[i] = true;
				}
				else if(vert_arr[(H.vert_location)[i]].key > tempen.w)
				{
					//printf("*****going to decrease key %d %lf (%d %d)\n",i,tempen.w, currver,i );
					tempeg.v1 = currver;
					tempeg.v2 = i;
					tempeg.w = tempen.w;
					H.Decrease_key(vert_arr[(H.vert_location)[i]],tempen.w,tempeg);
				}
			}
		}
		//H.print();
	}
	double ms_w = 0;
	for(i = 0;i<n-1;i++)
	{
		ms_w += answer[i].w;
	}
	printf("%.2f\n",ms_w );
	sort(answer,answer + n -1); ///just for printing in sorted order of weight
	for(i = 0;i<n-1;i++)
	{
		if(answer[i].v1 > answer[i].v2)
		{
			temp_int = answer[i].v2;
			answer[i].v2 = answer[i].v1;
			answer[i].v1 = temp_int;
		}
		printf("%d %d %.2f\n", answer[i].v1,answer[i].v2,answer[i].w);
	}
	return 0;
}