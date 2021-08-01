#include <bits/stdc++.h>
using namespace std;

class Node{
  
  public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    
};

Node* constructTree(int pre[], int min_val, int max_val, int* i, int n){
    
    if(*i>n){ return NULL; }
    
    Node* root = NULL;
    int curr = pre[*i];
    
    if(curr>min_val && curr<max_val){
        root = new Node(curr);
        if(*i<=n){
            *i = *i + 1;
            root->left = constructTree(pre, min_val, curr, i, n);
            root->right = constructTree(pre, curr, max_val, i, n);
        }
    }
    return root;
}


void printInorder(Node* root){
    if(!root){return;}
    if(root->left){printInorder(root->left);}
    cout<<root->data<<" ";
    if(root->right){printInorder(root->right);}
    return;
}

int main() {
    
    int pre[] = { 10, 5, 1, 7, 40, 50 };
    int n = sizeof(pre) / sizeof(pre[0]);

    int index = 0;
    Node* root = constructTree(pre, INT_MIN, INT_MAX, &index, n-1);
 
    cout << "Inorder traversal: ";
    printInorder(root);
    
    return 0;
}
