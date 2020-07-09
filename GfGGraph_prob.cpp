#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
    int V;
    list<int> *adj;
};

Graph* AdjList(int x){
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
        cout<<i<<"-->";
        for(auto it=G->adj[i].begin();it!=G->adj[i].end();++it){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
}

void BFS(Graph* G,int x){
    bool* visited = new bool[G->V];
    for(int i=0;i<G->V;i++){
        visited[i] = false;
    }
    visited[x] = true;
    list<int> Q;
    Q.push_back(x);
    while(!Q.empty()){
        x = Q.front();
        cout<<x<<" ";
        Q.pop_front();
        for(auto i=G->adj[x].begin();i!=G->adj[x].end();++i){
            if(!visited[*i]){
                visited[*i] = true;
                Q.push_back(*i);
            }
        }
    }
}

bool CyclicUtil(Graph* G,int x,bool vis[],int p){
    vis[x] = true;
    for(auto it=G->adj[x].begin();it!=G->adj[x].end();++it){
        if(!vis[*it]){
            (CyclicUtil(G,*it, vis, x));
        }
        else if (*it != p){
            return true;
        }
    }
    return false;
}

bool Cyclic(Graph* G){
    bool* vis = new bool[G->V];
    for(int i=0;i<G->V;i++){
        vis[i] = false;
    }
    for(int i=0;i<G->V;i++){
        if(!vis[i]){
            if(CyclicUtil(G,i,vis,-1)) return true; 
        }
    }
    return false;
}

bool MotherVertexUtil(Graph*G,bool visit[],int x){
    visit[x] = true;
    for(auto it = G->adj[x].begin();it!=G->adj[x].end();++it){
        if(!visit[*it]){
            MotherVertexUtil(G,visit,*it);
        }
    }
    for(int i=0;i<G->V;i++){
        if(!visit[i]){
            return false;
        }
    }
    return true;
}

void MotherVertex(Graph* G){
    bool* visit = new bool[G->V];
    for(int i=0;i<G->V;i++){
        visit[i] = false;
    }
    for(int j=0;j<G->V;j++){
        if(MotherVertexUtil(G,visit,j)){
            cout<<j<<" ";
        }
        for(int i=0;i<G->V;i++){
            visit[i] = false;
        }
    }
}

int NodesAtLevel(Graph* G,int x,int l){
    bool* place = new bool[G->V];
    for(int i=0;i<G->V;i++){
        place[i] = false;
    }
    int level[G->V];
    place[x] = true;
    list<int> Q;
    Q.push_back(x);
    level[x] = 0;
    while(!Q.empty()){
        int x = Q.front();
        Q.pop_front();
        for(auto it = G->adj[x].begin();it!=G->adj[x].end();++it){
            if(!place[*it]){
                place[*it] = true;
                level[*it] = level[x]+1;
                Q.push_back(*it);
            }
        }
    }
    int count = 0;
    for(int i=0;i<G->V;i++){
        if(level[i] == l){
            count++;
        }
    }
    return count;
}

int PossiblePathUtil(Graph* G,bool vi[],int x,int y,int& cou){
    vi[x] = true;
    vi[y] = false;
    if(x == y) cou++;
    for(auto it = G->adj[x].begin();it!=G->adj[x].end();++it){
        if(!vi[*it]){
            PossiblePathUtil(G,vi,*it,y,cou);
        }
    }
}

int PossiblePath(Graph* G,int x,int y){
    int cou = 0;
    bool* vi = new bool[G->V];
    for(int i=0;i<G->V;i++){
        vi[i] = false;
    }
    PossiblePathUtil(G,vi,x,y,cou);
    return cou;
}

void TopoSortUtil(Graph* G,bool pla[],int x,stack<int> &S){
    pla[x] = true;
    for(auto it = G->adj[x].begin();it!=G->adj[x].end();++it){
        if(!pla[*it]){
            TopoSortUtil(G,pla,*it,S);
        }
    }
    S.push(x);
}

void TopoSort(Graph* G,int x){
    bool* pla = new bool[G->V];
    for(int i=0;i<G->V;i++){
        pla[i] = false;
    }
    stack<int> S;
    TopoSortUtil(G,pla,x,S);
    for(int i=0;i<G->V;i++){
        if(!pla[i]){
            TopoSortUtil(G,pla,i,S);
        }
    }
    while(!S.empty()){
        cout<<S.top()<<" ";
        S.pop();
    }
}

int main() {
	Graph *g1,*g2,*g3;
	g1 = AdjList(5);
    addEdge(g1,1, 0); 
    addEdge(g1,0, 2); 
    addEdge(g1,2, 1); 
    addEdge(g1,0, 3); 
    addEdge(g1,3, 4); 
    Cyclic(g1)? cout << "Graph contains cycle\n": 
                   cout << "Graph doesn't contain cycle\n"; 
  
    g2 = AdjList(3);
    addEdge(g2,0, 1); 
    addEdge(g2,1, 2); 
    Cyclic(g2)? cout << "Graph contains cycle\n": 
                   cout << "Graph doesn't contain cycle\n"; 
    
    g3 = AdjList(5);
    addEdge(g3,0, 3); 
    addEdge(g3,0, 2); 
    addEdge(g3,1, 0); 
    addEdge(g3,2, 1); 
    addEdge(g3,3, 4); 
    //addEdge(g3,5, 6); 
    //addEdge(g3,5, 2); 
   // addEdge(g3,6, 0);
    MotherVertex(g3);
    cout<<endl<<NodesAtLevel(g3,0,2);
    Graph *g4;
    g4 = AdjList(5);
    addEdge(g4,0,1);
    addEdge(g4,0,2);
    addEdge(g4,0,4);
    addEdge(g4,1,4);
    addEdge(g4,1,3);
    addEdge(g4,2,4);
    addEdge(g4,3,2);
    cout<<endl<<PossiblePath(g4,0,4);
    Graph* g5;
    g5 = AdjList(6);
    addEdge(g5,5, 2); 
    addEdge(g5,5, 0); 
    addEdge(g5,4, 0); 
    addEdge(g5,4, 1); 
    addEdge(g5,2, 3); 
    addEdge(g5,3, 1); 
    cout<<endl;
    TopoSort(g5,5);
    return 0;
}
