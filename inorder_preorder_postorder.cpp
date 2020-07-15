#include<bits/stdc++.h>
using namespace std;

#define ll long long int

class node{

    public:
        int data;
        node* left;
        node* right;

        node(int val){
            this->data = val;
            this->left = NULL;
            this->right = NULL;
        }
};


void preorder(node* root){
    if(root==NULL){return;}
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}

void inorder(node* root){
    if(root==NULL){return;}
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}

void postorder(node* root){
    if(root==NULL){return;}
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    return;
}

int main(){

    node *root            = new node(1); 
    root->left            = new node(2); 
    root->right           = new node(3); 
    root->left->left      = new node(4); 
    root->left->right     = new node(5);
    
    cout<<"preorder: ";
    preorder(root);
    cout<<"\n";
    
    cout<<"inorder: ";
    inorder(root);
    cout<<"\n";
    
    cout<<"postorder: ";
    postorder(root);
    cout<<"\n";
    
    return 0;
}