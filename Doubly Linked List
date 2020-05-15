#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node *prev;
};

Node *head;

Node* GetNewNode(int x){
    Node *temp = new Node();
    temp->data = x;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

void InsertB(int x){
    Node *temp = GetNewNode(x);
    if (head == NULL){
        head = temp;
        return;
    }
    Node *temp2 = head;
    temp2->prev = temp;
    temp->next = temp2;
    head = temp;
}

void Insert(int x){
    Node *temp = GetNewNode(x);
    
    if (head == NULL){
        head = temp;
        return;
    }
    Node *temp2 = head;
    while(temp2->next != NULL){
        temp2 = temp2->next;
    }
    temp->prev = temp2;
    temp2->next = temp;
    
}

void InsertN(int x, int n){
    Node *temp = GetNewNode(x);
    if (n==1){
        head = temp;
        return;
    }
    Node *temp2 = head;
    for (int i = 0;i<n-2;i++){
        temp2 = temp2->next;
    }
    Node *temp3 = temp2->next;
    temp3->prev = temp;
    temp->next = temp2->next;
    temp2->next = temp;
    temp->prev = temp2;
    
}

void Delete(int n){
    Node *temp = head;
    if (n==1){
        head = NULL;
        delete(temp);
        return;
    }
    Node *temp2;
    for (int i = 0;i<n-2;i++){
        temp = temp->next;
    }
    Node *temp3 = temp2->next;
    temp2 = temp->next;
    temp->next = temp2->next;
    temp3->prev = temp;
    delete(temp2);
}

/*void Reverse(){
    Node *temp = head;
    
    if (head == NULL) return;
    Node *temp2;
    while(temp != NULL){
        temp2 = temp->prev;
        temp->prev = temp->next;
        temp->next = temp2;
        temp = temp->prev;
    }
    
    head = temp2->prev;
}*/

void ReversePrint(){
    Node *temp = head;
    
    if (head == NULL) return;
    
    while(temp->next !=NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

void Print(){
    Node *temp =head;
    
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    head = NULL;
    
   
    Insert(3);
    Insert(2);
    InsertN(1,2);
    InsertB(6);
    InsertB(7);
    Print();
    cout<<endl;
    
    ReversePrint();
    
    
	
	return 0;
}
