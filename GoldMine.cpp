#include <bits/stdc++.h>
using namespace std;

int dp[100][100];
int vis[100][100];

int GoldMine(int m,int n,int Gold[3][3]){
    if(n >= 2){
        return Gold[m][n];
    }
    if(vis[m][n] == 1){
        return dp[m][n];
    }
    int sum = Gold[m][n] + GoldMine(m,n+1,Gold);
    if(m < 3){
        sum = max(sum,Gold[m][n]+GoldMine(m+1,n+1,Gold));
    }
    if(m >= 0){
        sum = max(sum,Gold[m][n] + GoldMine(m-1,n+1,Gold));
    }
    dp[m][n] = sum;
    vis[m][n] = 1;
    return dp[m][n];
}

int main() {
	int Gold[3][3];
	int m,n,x;
	cin>>m>>n;
	for(int i=0;i<m;i++){
	    for(int j=0;j<n;j++){
	        cin>>Gold[i][j];
	    }
	}
	int res = GoldMine(0,0,Gold);
	for(int i=1;i<3;i++){
	    res = max(res,GoldMine(i,0,Gold));
	}
	cout<<res;
	return 0;
}
