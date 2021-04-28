#include <bits/stdc++.h>
using namespace std;

class Edge{
public:
	int src,dest,wt;
};

class Graph{
public:
	int V;
	int E;
	Edge* edge;
};

Graph* createGraph(int x,int y){
	Graph* G = new Graph();
	G->V = x;
	G->E = y;
	G->edge = new Edge[G->E];
	return G;
}

class Subset{
public:
	int parent,rank;
};

int find(Subset subset[],int i){
	if(subset[i].parent != i){
		return find(subset,subset[i].parent);
	}
	return subset[i].parent;
}

void Union(Subset subset[],int x,int y){
	int xroot = find(subset,x);
	int yroot = find(subset,y);
	if(subset[xroot].rank > subset[yroot].rank){
		subset[yroot].parent = xroot;
	}
	else if(subset[xroot].rank < subset[yroot].rank){
		subset[xroot].parent = yroot;
	}
	else{
		subset[yroot].parent = xroot;
		subset[xroot].rank++;
	}
}

int myComp(const void* a, const void* b){  
    Edge* a1 = (Edge*)a;  
    Edge* b1 = (Edge*)b;  
    return a1->wt > b1->wt;  
}  

void KruskalMST(Graph* G){
	Subset* subset = new Subset[G->V*sizeof(int)];
	for(int i=0;i<G->V;i++){
		subset[i].parent = i;
		subset[i].rank = 0;
	}
	Edge result[G->V];
	qsort(G->edge, G->E, sizeof(G->edge[0]), myComp);  
	int c = 0;
	int e =0;
	while(e < (G->V-1) && c < G->E){
		Edge next_edge = G->edge[c++];
		int x = find(subset,next_edge.src);
		int y = find(subset,next_edge.dest);
		if(x != y){
			result[e++] = next_edge;
			Union(subset,x,y);
		}
	}
	for(int i=0;i<e;i++){
		cout<<result[i].src<<"-->"<<result[i].dest<<"with wt = "<<result[i].wt<<endl;
	}
}

int main(){
	int V = 4;   
    int E = 5;
    Graph* G = createGraph(V, E);  
  
  
    // add edge 0-1  
    G->edge[0].src = 0;  
    G->edge[0].dest = 1;  
    G->edge[0].wt = 10;  
  
    // add edge 0-2  
    G->edge[1].src = 0;  
    G->edge[1].dest = 2;  
    G->edge[1].wt = 6;  
  
    // add edge 0-3  
    G->edge[2].src = 0;  
    G->edge[2].dest = 3;  
    G->edge[2].wt = 5;  
  
    // add edge 1-3  
    G->edge[3].src = 1;  
    G->edge[3].dest = 3;  
    G->edge[3].wt = 15;  
  
    // add edge 2-3  
    G->edge[4].src = 2;  
    G->edge[4].dest = 3;  
    G->edge[4].wt = 4;  
  
    KruskalMST(G);  
	return 0;
}
