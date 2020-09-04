#include <bits/stdc++.h>
using namespace std;
const int MAX = 100; 

void dfs(int adj[][MAX],int i,int j,int N,int M,bool visit[][MAX]){
    visit[i][j] = true;
    
    if(i+1 < N && adj[i][j] >= adj[i+1][j] && !visit[i+1][j]){
        dfs(adj,i+1,j,N,M,visit);
    }
    if(j+1 < M && adj[i][j] >= adj[i][j+1] && !visit[i][j+1]){
        dfs(adj,i,j+1,N,M,visit);
    }
    if(i-1 >= N && adj[i][j] >= adj[i-1][j] && !visit[i-1][j]){
        dfs(adj,i-1,j,N,M,visit);
    }
    if(j-1 >= 0 && adj[i][j] >= adj[i][j-1] && !visit[i][j-1]){
        dfs(adj,i,j-1,N,M,visit);
    }
}

void PrintMinInitial(int N,int M,int adj[][MAX]){
    vector<pair<long int, pair<int,int>>> v;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            v.push_back(make_pair(adj[i][j],make_pair(i,j)));
        }
    }
    sort(v.begin(),v.end());
    
    bool visit[N][MAX];
    memset(visit,false,sizeof(visit));
    
    for(int i=v.size()-1;i>=0;i--){
        if(!visit[v[i].second.first][v[i].second.second]){
            visit[v[i].second.first][v[i].second.second] = true;
            cout<<v[i].second.first<<" "<<v[i].second.second<<endl;
            dfs(adj,v[i].second.first,v[i].second.second,N,M,visit);
        }
    }
    
}

int main() {
	int N,M;
	cin>>N>>M;
	int adj[N][MAX];
	for(int i=0;i<N;i++){
	    for(int j=0;j<M;j++){
	        cin>>adj[i][j];
	    }
	}
	PrintMinInitial(N,M,adj);
	return 0;
}
