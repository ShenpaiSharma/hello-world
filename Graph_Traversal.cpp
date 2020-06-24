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

/*void DFStimerRec(Graph* G,bool reach[],int x,int intime[],int outtime[],int timer){
    reach[x] = true;
    ++timer;
    intime[x] = timer;
    auto it = G->adj[x].begin();
    while(it != G->adj[x].end()){
        if(!reach[*it]){
            DFStimerRec(G,reach,*it,intime,outtime,timer);
        }
    }
    ++timer;
    outtime[x] = timer;
}

void DFStimer(Graph* G,int x){
    int timer= 0;
    bool* reach = new bool[G->V];
    int* intime = new int[G->V];
    int* outtime = new int[G->V];
    for(int i=0;i<G->V;i++){
        reach[i] = false;
        intime[i] = 0;
        outtime[i] = 0;
    }    
    DFStimerRec(G,reach,x,intime,outtime,timer);
    for(int i=0;i<G->V;i++){
        if(!reach[i]){
            DFStimerRec(G,reach,i,intime,outtime,timer);
        }
    }
    for(int i=0;i<G->V;i++){
        cout<<intime[i]<<" "<<outtime[i]<<endl;
    }
    //return (((intime[u] < intime[v]) && (outtime[u] > outtime[v])) || ((intime[u] > intime[v]) && (outtime[u] < outtime[v])));
}*/

bool isReachable(Graph* G,int x,int y){
    bool* reached = new bool[G->V];
    for(int i=0;i<G->V;i++){
        reached[i] = false;
    }
    if (x==y) return true;
    list<int> Qu;
    Qu.push_back(x);
    reached[x] = true;
    while(!Qu.empty()){
        x = Qu.front();
        Qu.pop_front();
        for(auto it = G->adj[x].begin(); it != G->adj[x].end(); ++it){
            if(*it == y){
                return true;
            }
            else{
                if(!reached[*it]){
                    reached[*it] = true;
                    Qu.push_back(*it);
                }
            }
        }
    }
    return false;
}

bool isCycleRec(Graph* G,int x,bool place[],bool stack[]){
    if (place[x] == false){
        place[x] = true;
        stack[x] = true;
    }
    for(auto it = G->adj[x].begin();it != G->adj[x].end();++it){
        if(!place[*it] && isCycleRec(G,*it,place,stack)){
            return true;
        }
        else if(stack[*it]){
            return true;
        }
    }
    stack[x] = false;
    return false;
}

bool isCycle(Graph* G){
    bool* place = new bool[G->V];
    bool* stack = new bool[G->V];
    for(int i=0;i<G->V;i++){
        place[i] = false;
        stack[i] = false;
    }
    for(int i=0;i<G->V;i++){
        if (isCycleRec(G,i,place,stack)){
            return true;
        }
    }
    return false;
}

int main() {
	Graph* G;
	G = Adjlist(4);
	/*addEdge(G,5,0);
	addEdge(G,4,0);
	addEdge(G,5,2);
	addEdge(G,2,3);
	addEdge(G,3,1);
	addEdge(G,4,1);
	*/
	addEdge(G,0,1);
	addEdge(G,1,2);
	//addEdge(G,2,0);
	addEdge(G,0,2);
	addEdge(G,2,3);
	Print(G);
	cout<<endl;
	BFS(G,0);
	cout<<endl;
	DFS(G,0);
	cout<<endl;
	TopoSort(G,0);
	cout<<endl;
    //(DFStimer(G,5));
    if(isReachable(G,0,3)) cout<<"YES";
    else cout<<"NO";
    cout<<endl;
    if(isCycle(G)) cout<<"Yes";
    else cout<<"NO";
	return 0;
}
