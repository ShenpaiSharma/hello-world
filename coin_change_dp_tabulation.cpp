#include <iostream>
using namespace std;

int Solve(int n){
    int dp[2*n+1];
    dp[0] = 0;
    dp[1] = 1;
    for(int i=-5;i<0;i++){
        dp[i] = 0;
    }
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2]; 
    }
    return dp[n];
}

int main() {
	cout<<Solve(4);
	return 0;
}
