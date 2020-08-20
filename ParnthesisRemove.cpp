#include <bits/stdc++.h>
using namespace std;

bool ParenthesisCheck(string a){
    stack<int> S;
    for(int i=0;i<a.size();i++){
        if(a[i] == '('){
            S.push(a[i]);
        }
        else{
            if(S.empty()){
                return false;
            }
            else S.pop();
        }
    }
    if(S.empty()) return true;
    else return false;
}

vector<string> MinParanToBeremoved(string a){
    map<string,bool> vis;
    vector<string> ans;
    int found = 0;
    queue<string> Q;
    Q.push(a);
    while(!Q.empty()){
        string s = Q.front();
        Q.pop();
        if(vis[s]) continue;
        vis[s] = 1; 
        if(ParenthesisCheck(s)) found = 1,ans.push_back(s);
        if(found) continue;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == ')'){
                string v = s.substr(0,i) + s.substr(i+1,s.size());
                Q.push(v);
            }
        }
    }
    return ans;
}

int main() {
	string a;
	cin>>a;
	vector<string> v;
	v = MinParanToBeremoved(a);
	for(auto x:v){
	    cout<<x<<" ";
	}
	return 0;
}
