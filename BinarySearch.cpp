#include <bits/stdc++.h>
using namespace std;

int BinaryS(vector<int> arr,int start,int end,int x){
    if(end >= start){
        int mid = start + (end - 1)/2;
        
        if(arr[mid] == x){
            return mid;
        }
        if(arr[mid] > x){
            return BinaryS(arr,start,mid-1,x);
        }
        
        return BinaryS(arr,mid+1,end,x);
        
    }    
    return -1;
}

int main() {
	vector<int> arr;
	int x,n;
	cin>>n;
	for(int i=0;i<n;i++){
	    cin>>x;
	    arr.push_back(x);
	}
	int s;
	cin>>s;
	sort(arr.begin(),arr.end());
	cout<<BinaryS(arr,0,n-1,s);
	return 0;
}
