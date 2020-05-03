#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

Node *head;

void Insert(int x){
    Node *temp = new Node();
    temp->data = x;
    temp->next = NULL;
    
    if(head == NULL){
        head = temp;
        return;
    }
    Node *temp2 = head;
    while(temp2->next != NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp;
}

void InsertB(int x){
    Node *temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
} 

void Insertn(int x, int n){
    Node *temp1 = new Node();
    temp1 -> data = x;
    temp1 -> next = NULL;
    
    if (n==1){
        temp1->next = head;
        head = temp1;
        return;
    }
    Node *temp2 = head;
    
    for (int i = 0;i<n-2;i++){
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}
void Delete(int n){
    Node *temp;
    temp = head;
    
    if (n==1){
        head = temp->next;
        delete(temp);
        return;
    }
    Node *temp2;
    for (int i = 0;i<n-2;i++){
        temp = temp->next;
    }
    temp2 = temp->next;
    temp->next = temp2->next;
    delete(temp2);
}

void Reverse(){
    Node *prev,*current,*next;
    prev = NULL;
    current = head;
    
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    
}

void Print(){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;

    }
}

int main() {
    head = NULL;
    Insert(2);
    Insert(4);
    Insert(5);
    InsertB(1);
    Insertn(3,3);
    Print();
    cout << "\n";
    Delete(3);
    Print();
    cout << "\n";
    Reverse();
    Print();
	
	return 0;
}

