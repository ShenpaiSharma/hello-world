#include <bits/stdc++.h>
using namespace std;

vector<int> Level(vector<int> adj[],int V){
    bool* vis = new bool[V];
    for(int i=0;i<V;i++){
        vis[i] = false;
    }
    vector<int> level;
    for(int i=0;i<V;i++){
        level.push_back(-1);
    }
    level[0] = 0;
    queue<int> Q;
    Q.push(0);
    while(!Q.empty()){
        int s = Q.front();
        Q.pop();
        for(auto it = adj[s].begin(); it != adj[s].end();++it){
            if(!vis[*it]){
                vis[*it] = true;
                level[*it] = level[s]+1;
                Q.push(*it);
            }
        }
    }
    return level;
}

int main() {
    int V,E;
    cin>>V>>E;
    vector<int> adj[V];
    for(int i=0;i<E;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<int> ans = Level(adj,V);
    cout<<count(ans.begin(),ans.end(),2);
	return 0;
}
