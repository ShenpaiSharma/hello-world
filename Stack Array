#include <iostream>
using namespace std;

int A[10];
int top = -1;

void Push(int x){
    if (top == 9){
        cout << "Stack Overflow"<<endl;
        return;
    }    
    A[++top] = x;
}

void Pop(){
    if (top == -1){
        cout << "Already Empty" << endl;
        return;
    }
    top--;
}

void Top(){
    cout << A[top] <<endl;
}

void IsEmpty(){
    if (top == -1){
        cout << "True"<<endl;
    }
    else {
        cout << "False"<<endl;
    }
}

void Print(){
    for (int i=0;i<=top;i++){
        cout << A[i] << " ";
    }
}

int main() {
	Push(1);
	Push(2);
	Push(3);
	Top();
	Pop();
	IsEmpty();
	Print();
	return 0;
}
