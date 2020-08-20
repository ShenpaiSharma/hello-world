#include <bits/stdc++.h>
using namespace std;


vector<int> v;

int fun(int start,int end){
    if(start+1 == end) return 1;
    int mid = v[start];
    if(mid == end) return 2*fun(start+1,end-1);
    return fun(start,mid) + fun(mid+1,end);
}

int Score(string a){
    int n = a.size();
    v.resize(n,0);
    stack<int> S;
    for(int i=0;i<n;i++){
        if(a[i] == ')'){
            int t = S.top();
            v[t] = i;
            S.pop();
        }
        else S.push(i);
    }
    return fun(0,n-1);
}

int main() {
	string a;
	cin>>a;
    cout<<Score(a);
	return 0;
}
