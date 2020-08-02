#include <iostream>
using namespace std;

int Solution(int n){
    if(n ==1){
        return 0;
    }
    int ans = 1+Solution(n-1);
    if(n%2 == 0){
        ans = min(ans,(1+Solution(n/2)));
    }
    if(n%3 == 0){
        ans = min(ans,(1+Solution(n/3)));
    }
    return ans;
}

int SolutionDP(int* dp,int n){
    if(n == 1){
        return 0;
    }
    if(dp[n] > 0){
        return dp[n];
    }
    int ans = 1+SolutionDP(dp,n-1);
    if(n%2 == 0){
        ans = min(ans,1+SolutionDP(dp,n/2));
    }
    if(n%3 == 0){
        ans = min(ans,1+SolutionDP(dp,n/3));
    }
    dp[n] = ans;
    return ans;
}

int SolutinBottomUp(int n){
    int dp1[n+1];
    dp1[1] = 0;
    dp1[0] = 0; 
    int ans;
    for(int i=2;i<=n;i++){
        ans = 1 + dp1[i-1];
        if(n%2 == 0){
            ans = min(ans,1+dp1[i/2]);
        }
        if(n%3 == 0){
            ans = min(ans,1+dp1[i/3]);
        }
        dp1[i] = ans;
    }
    return dp1[n];
}

int main() {
	int n;
	cin>>n;
	int* dp = new int[n+1];
	for(int i=0;i<n;i++){
	    dp[i] = 0;
	}
	cout<<SolutinBottomUp(n);
	delete [] dp;
	return 0;
}
