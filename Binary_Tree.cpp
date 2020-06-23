#include <bits/stdc++.h>
using namespace std;

class BstNode{
    public:
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode* GetNewNode(int x){
    BstNode *temp = new BstNode();
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

BstNode* Insert(BstNode* root, int data){
    BstNode *temp = GetNewNode(data);
    if (root == NULL){
        root = temp;
    }
    else if(data <= root->data){
        root->left = Insert(root->left, data);
    }
    else{
        root->right = Insert(root->right, data);
    }
    return root;
}

int FindMin(BstNode* root){
    BstNode *temp;
    if (root == NULL){ 
        cout << "ERROR...\n";
        return -1;
    }    
    else{
        temp = root;
        while(temp->left != NULL){
            temp = temp->left;
        }
        return temp->data;
    }
}

int FindMax(BstNode* root){
    BstNode *temp;
    if (root == NULL){ 
        cout << "ERROR...\n";
        return -1;
    }    
    else{
        temp = root;
        while(temp->right != NULL){
            temp = temp->right;
        }
        return temp->data;
    }
}

int Search(BstNode* root, int data){
    if (root == NULL) return 0;
    else if (data == root->data) return 1;
    
    else if (data <= root->data){
        return Search(root->left, data);
    }
    else{
        return Search(root->right, data);
    }
}

void LevelOrder(BstNode *root){
    if (root == NULL) return;
    queue<BstNode*> Q;
    
    Q.push(root);
    
    while(!Q.empty()){
        BstNode *temp = Q.front();
        cout << temp->data<<" ";
        
        if (temp->left != NULL) Q.push(temp->left);
        if (temp->right != NULL) Q.push(temp->right);
        Q.pop();
    }
}

void Preorder(BstNode *root){
    if (root == NULL) return;
    
    cout << root->data<< " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(BstNode *root){
    if (root == NULL) return;
    
    Inorder(root->left);
    cout<< root->data<< " ";
    Inorder(root->right);
}

void Postorder(BstNode *root){
    if (root == NULL) return;
    
    Postorder(root->left);
    Postorder(root->right);
    cout<< root->data<< " ";
}

BstNode* FindMinNode(BstNode* root){
    BstNode *temp;
    if (root == NULL){ 
        cout << "ERROR...\n";
        return root;
    }    
    else{
        temp = root;
        while(temp->left != NULL){
            temp = temp->left;
        }
        return temp;
    }
}

BstNode* Delete(BstNode *root, int data){
    if (root == NULL) return root;
    else if (data < root->data){
        root->left = Delete(root->left, data);
    }
    else if(data > root->data){
        root->right = Delete(root->right, data);
    }
    else{
        if (root->left == NULL && root->right == NULL){
            delete(root);
            root = NULL; // dangling pointer
        }
        else if (root->left == NULL){
            BstNode *temp = root;
            root = root->right;
            delete(temp);
        }
        else if (root->right == NULL){
            BstNode *temp = root;
            root = root->left;
            delete(temp);
        }
        else{
            BstNode *temp = FindMinNode(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

int FindHeight(BstNode *root){
    if (root == NULL) return -1;
    
    int leftH = FindHeight(root->left);
    int rightH = FindHeight(root->right);
    
    return (max(leftH, rightH)+1);
}

void topView(Node *root) {
    if (root == NULL){
        return;
    }
unordered_map<int,int> m;
queue<pair<Node*, int>> q;
q.push(make_pair(root,0));
        

while(!q.empty()){
    pair<Node*,int> p = q.front();

    Node *temp = p.first;
    int val = p.second;
    q.pop();
    if (m.count(val) == 0){
        m[val] = temp->data;
                
    }
    if(temp->left !=NULL){
        q.push(make_pair(temp->left,val-1));
    }
    if (temp->right != NULL){
        q.push(make_pair(temp->right,val+1));
    }
}
vector<pair<int,int>> v;
for(auto x:m){
        v.push_back(x);
        
    }
    sort(v.begin(),v.end());
    for(auto it=v.begin();it!=v.end();++it){
        cout<<(*it).second<<" ";
    }
        
}

int main() {
	BstNode *root = NULL;
	
	root = Insert(root,4);
	root = Insert(root, 2);
	root = Insert(root, 6);
	root = Insert(root, 7);
	root = Insert(root,8);
	root = Insert(root, 11);
	root = Insert(root, 1);
	root = Insert(root, 9);
	
	root = Delete(root, 11);
	
	LevelOrder(root);
	cout << endl;
	Preorder(root);
	cout << endl;
	Inorder(root);
	cout << endl;
	Postorder(root);
	cout << endl;
	cout << FindMax(root)<<endl;
	cout<< FindMin(root)<<endl;
	cout << FindHeight(root)<<endl;
	if (Search(root, 7) == 1) cout << "Found";
	else cout << "NO";
	return 0;
}
