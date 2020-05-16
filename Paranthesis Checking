#include <bits/stdc++.h>
using namespace std;

char o[4] = "({[";
char c[4] = ")}]";

int index(char x){
    
    if (x == ')'){
        return 0;
    }
    else if (x == '}'){
        return 1;
    }
    else if (x == ']'){
        return 2;
    }
    
}

int checkParan(char k[], int n){
    stack<char> s;
    int j;
    for (int i=0; i<n; i++){
        if (k[i] == o[0] || k[i] == o[1] || k[i] == o[2]){
            s.push(k[i]);
            
        }
        else if(k[i] == c[0] || k[i] == c[1] || k[i] == c[2]){
            j = index(k[i]);
            if (s.empty() || s.top() != o[j]){
                return 0;
            }
            else{
                s.pop();
            }
        }
    }
    if (s.empty()){
        return 1;
    }
}

int main() {
    char a[] = "({})[]";
	int y = checkParan(a,strlen(a));
	if (y == 1){
	    cout << "Right Paranthesis";
	}
	else{
	    cout << "Wrong Paranthensis";
	}
	
	return 0;
}
