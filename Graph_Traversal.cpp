#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int V;
    list<int> *adj;
};

Graph* Adjlist(int x){
    Graph* G = new Graph();
    G->V = x;
    G->adj = new list<int>[G->V];
    return G;
}

void addEdge(Graph* G,int u,int v){
    G->adj[u].push_back(v);
}

void Print(Graph* G){
    for(int i=0;i<G->V;i++){
        cout<<i;
        for(auto it = G->adj[i].begin(); it != G->adj[i].end();++it){
            cout<<"-->"<<*it;
        }
        cout<<endl;
    }
}

void BFS(Graph* G,int s){
    bool *visited = new bool[G->V];
    for(int i=0;i<G->V;i++){
        visited[i] = false;
    }
    visited[s] = true;
    list<int> Q;
    Q.push_back(s);
    while(!Q.empty()){
        s = Q.front();
        cout<<s<<" ";
        Q.pop_front();
        for(auto it = G->adj[s].begin(); it != G->adj[s].end();++it){
            if(!visited[*it]){
                visited[*it] = true;
                Q.push_back(*it);
            }
        }
    }
}

void DFSRec(Graph* G,bool vis[],int x){
    vis[x] = true;
    cout<<x<<" ";
    for(auto it=G->adj[x].begin(); it != G->adj[x].end();++it){
        if(!vis[*it]){
            DFSRec(G,vis,*it);
        }
    }
}

void DFS(Graph* G,int s){
    bool* visited = new bool[G->V];
    for(int i=0;i<G->V;i++){
        visited[i] = false;
    }
    DFSRec(G,visited,s);
    for(int i=0;i<G->V;i++){
        if(!visited[i]){
            DFSRec(G,visited,i);
        }
    }
}

stack<int> S;
void TopoRec(Graph* G,int x,bool visit[]){
    visit[x] = true;
    for(auto it = G->adj[x].begin(); it != G->adj[x].end(); ++it){
        if(!visit[*it]){
            TopoRec(G,*it,visit);
        }
    }
    S.push(x);
}

void TopoSort(Graph* G,int s){
    bool* visit = new bool[G->V];
    for(int i=0;i<G->V;i++){
        visit[i] = false;
    }
    TopoRec(G,s,visit);
    for(int i=0;i<G->V;i++){
        if(!visit[i]){
            TopoRec(G,i,visit);
        }
    }
    while(!S.empty()){
        cout<<S.top()<<" ";
        S.pop();
    }
}

int main() {
	Graph* G;
	G = Adjlist(6);
	addEdge(G,5,0);
	addEdge(G,4,0);
	addEdge(G,5,2);
	addEdge(G,2,3);
	addEdge(G,3,1);
	addEdge(G,4,1);
	Print(G);
	cout<<endl;
	BFS(G,5);
	cout<<endl;
	DFS(G,5);
	cout<<endl;
	TopoSort(G,5);
	return 0;
}
