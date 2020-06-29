#include <iostream>
using namespace std;

class Graph{
    public:
    int V;
    int **Adj;
};

Graph* AdjMatrix(int x){
    Graph *G = new Graph();
    G->V = x;
    G->Adj = new int*[G->V];
    for(int i=0;i<x;i++){
        G->Adj[i] = new int[G->V];
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            G->Adj[i][j] = 0;
        }
    }
    return G;
}

void addEdge(Graph* G,int u,int v){
    G->Adj[u][v] =1;
}

void Print(Graph* G){
    for(int i=0;i<G->V;i++){
        for(int j=0;j<G->V;j++){
            cout<<G->Adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
	Graph* G;
	G = AdjMatrix(4);
	addEdge(G,0,1);
	addEdge(G,0,2);
	addEdge(G,1,2);
	addEdge(G,2,0);
	addEdge(G,2,3);
	addEdge(G,3,3);
	Print(G);
	return 0;
}
