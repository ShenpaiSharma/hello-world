#include <iostream>
using namespace std;

class Edge{
    public:
    int src,dest,wt;
};

class Graph{
    public:
    int V,E;
    Edge* edge;
};

class Subset{
    public:
    int parent;
    int rank;
};

Graph* AdjList(int V,int E){
    Graph* G = new Graph();
    G->E = E;
    G->V = V;
    G->edge = new Edge[G->E];
    return G;
}

int find(Subset subsets[],int i){
    if(subsets[i].parent != i){
        subsets[i].parent = find(subsets,subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(Subset subsets[],int x,int y){
    int xroot = find(subsets,x);
    int yroot = find(subsets,y);
    if(subsets[xroot].rank < subsets[yroot].rank){
        subsets[xroot].parent = yroot;
    }
    else if(subsets[xroot].rank > subsets[yroot].rank){
        subsets[yroot].parent = xroot;
    }
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void KruskalMST(Graph* G){
    Subset* subsets = new Subset[G->V*sizeof(Subset)];
    for(int i=0;i<G->E;i++){
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    Edge result[G->V];
    int count = 0;
    int e=0;
    while(e < (G->V)-1 && count < G->E){
        Edge next = G->edge[count++];
        int x = find(subsets,next.src);
        int y = find(subsets,next.dest);
        if(x != y){
            result[e++] = next;
            Union(subsets,x,y);
        }
    }
    for(count=0;count<e;++count){
        cout<<result[count].src<<"-->"<<result[count].dest<<" "<<result[count].wt<<endl;
    }
}

int main() {
	Graph* graph;
	graph = AdjList(4,5);
	
	graph->edge[0].src = 0;  
    graph->edge[0].dest = 1;  
    graph->edge[0].wt = 10;  
  
    // add edge 0-2  
    graph->edge[1].src = 0;  
    graph->edge[1].dest = 2;  
    graph->edge[1].wt = 6;  
  
    // add edge 0-3  
    graph->edge[2].src = 0;  
    graph->edge[2].dest = 3;  
    graph->edge[2].wt = 5;  
  
    // add edge 1-3  
    graph->edge[3].src = 1;  
    graph->edge[3].dest = 3;  
    graph->edge[3].wt = 15;  
  
    // add edge 2-3  
    graph->edge[4].src = 2;  
    graph->edge[4].dest = 3;  
    graph->edge[4].wt = 4;  
  
    KruskalMST(graph);  
	
	return 0;
}
