#include <bits/stdc++.h>
using namespace std;

int dp[100][100];
int vis[100][100];

int CoinChange(int n,int* coin,int k){
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 0;
    }
    if(k == 0){
        return 0;
    }
    if(vis[n][k] == 1){
        return dp[n][k];
    }
    int c = CoinChange(n-coin[0],coin,k);
    int d = CoinChange(n,coin+1,k-1);
    dp[n][k] = c+d;
    vis[n][k] = 1;
    return dp[n][k];
}

int main() {
    int n,k;
    cin>>n>>k;
    int coin[k];
    for(int i=0;i<k;i++){
        cin>>coin[i];
    }
    
    cout<<CoinChange(n,coin,k);
	return 0;
}
