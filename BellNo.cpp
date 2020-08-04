#include <iostream>
using namespace std;

int stirling(int** dp,int n,int k){
    if(n == 0 || k == 0 || k > n){
        return 0;
    }
    if(k == 1 || n == k){
        return 1;
    }
    if(dp[n][k] > 0){
        return dp[n][k];
    }
    return dp[n][k] = k*stirling(dp,n-1,k) + stirling(dp,n-1,k-1);
}

int main() {
    int n,k;
    cin>>n>>k;
    int** dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[k+1];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j] = 0;
        }
    }
    int sum;
    for(int i=1;i<=n;i++){
        sum += stirling(dp,n,i);
    }
    cout<<sum;
	return 0;
}
