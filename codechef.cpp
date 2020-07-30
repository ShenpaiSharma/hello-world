#include <iostream>
using namespace std;

long long Power(int arr[],int n){
    long long p=0;
    int index = 0;
    for(int i=1;i<n-1;i++){
        if((arr[index] > arr[i]) || (arr[index] == arr[i] && arr[index] > 0)){
            p += (i-index)*(arr[index]) + (i*i-index*index)*(arr[index]*arr[index]);
            index = i;
        }
    }
    p += ((n-1)-index)*(arr[index]) + ((n-1)*(n-1)-(index*index))*(arr[index]*arr[index]);
    return p;
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	cout<<Power(arr,n);
	return 0;
}
