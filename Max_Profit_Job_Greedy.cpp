#include<bits/stdc++.h>
using namespace std;

class Job{
  	public:
    int start,end,prfit;
};

bool compare(Job a, Job b){
    return a.end < b.end;
}

int MaxProfit(Job arr[],int n){
    sort(arr,arr+n,compare);
    vector<int> dp;
    int p;
    for(int i=1;i<n;i++){
        p = arr[i].prfit;
        for(int j=0;j<i;j++){
            if(arr[i].start >= arr[j].end){
                p += arr[j].prfit;
            }
        }
        dp.push_back(p);
        p=0;
    }
    return *max_element(dp.begin(), dp.end()); 
}

int main()
{
    int n;
    cin>>n;
    Job arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].start>>arr[i].end>>arr[i].prfit;
    }
    cout<<MaxProfit(arr,n);
    return 0;
}
