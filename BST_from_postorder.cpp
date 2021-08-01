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

Node* constructTree(int post[], int min_val, int max_val, int* i, int n){
    
    if(*i<0){ return NULL; }
    
    Node* root = NULL;
    int curr = post[*i];
    
    if(curr>min_val && curr<max_val){
        root = new Node(curr);
        if(*i>=0){
            *i = *i - 1;
            root->right = constructTree(post, curr, max_val, i, n);
            root->left = constructTree(post, min_val, curr, i, n);
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
    
    int post[] = {1, 7, 5, 50, 40, 10};
    int n = sizeof(post) / sizeof(post[0]);

    int index = n-1;
    Node* root = constructTree(post, INT_MIN, INT_MAX, &index, n-1);
 
    cout << "Inorder traversal: ";
    printInorder(root);
    
    return 0;
}
