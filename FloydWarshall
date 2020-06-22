#include <iostream>
using namespace std;

const int INF =  100000;

class Graph{
    public:
    int V;
    int **adj;
};

Graph* AdjMatrix(int x,int a[][4]){
    Graph* G = new Graph();
    G->V = x;
    G->adj = new int*[G->V];
    for(int i=0;i<G->V;i++){
        G->adj[i] = new int[G->V];
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<x;j++){
            G->adj[i][j] = a[i][j];
        }
    }
    return G;
}

Graph* Floydmarshall(Graph* G){
    int d[G->V][G->V];
    for(int i=0;i<G->V;i++){
        for(int j=0;j<G->V;j++){
            d[i][j] = G->adj[i][j]; 
        }
    }
    for(int k=0;k<G->V;k++){
        for(int i=0;i<G->V;i++){
            for(int j=0;j<G->V;j++){
                if(d[i][k]+d[k][j] < d[i][j]){
                    d[i][j] = d[i][k]+d[k][j];
                }
            }
        }
    }
    for(int i=0;i<G->V;i++){
        for(int j=0;j<G->V;j++){
            G->adj[i][j] = d[i][j];
        }
    }
    return G;
}

void Print(Graph* G){
    for(int i=0;i<G->V;i++){
        for(int j=0;j<G->V;j++){
            if (G->adj[i][j] == INF){
                cout<< "INF ";
            }
            else cout<<G->adj[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
	Graph* G;
	Graph* Gr;
    int v = 4;
    int a[4][4] = {{0,5,INF,10},{INF,0,3,INF},{INF,INF,0,1},{INF,INF,INF,0}};
	G = AdjMatrix(v,a);
	Print(G);
	Gr = Floydmarshall(G);
	cout<<endl;
	Print(Gr);
	return 0;
}
