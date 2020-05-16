#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

Node *top;

void Push(int x){
    Node *temp = new Node();
    temp->data = x;
    temp->next = top;
    top = temp;
}

void Pop(){
    Node *temp;
    
    if (top == NULL){
        cout << "Already Empty"<< endl;
        return;
    }
    temp = top;
    top = temp->next;
    delete(temp);
}

void Top(){
    if (top == NULL){
        cout << "Nothing Present"<<endl;
        return;
    }
    Node *temp;
    temp = top;
    cout << temp->data << endl;
}

void Print(){
    Node *temp = top;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
	top = NULL;
	Push(1);
	Push(2);
	Push(3);
	Pop();
	Top();
	Print();
	
	return 0;
}
