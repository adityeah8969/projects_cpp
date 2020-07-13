#include<bits/stdc++.h>
using namespace std;

#define ll long long int

//  A vertex cover of an undirected graph is a subset of its vertices such that 
//  for every edge (u, v) of the graph, either ‘u’ or ‘v’ is in vertex cover.

class node{
    public:
        int data;
        int vc;
        node* left;
        node* right;
};

node* newNode(int x){
    node* temp = new node();
    temp->data = x;
    temp->vc = 0;
    temp->left = NULL;
    temp->right= NULL;  
    return temp;
}

int vertex_cover(node* root){
    
    // for only one node answer is zero, leaves are also not included because there parents can 
    // have more connections than them.
    if(root == NULL || (root->left == NULL && root->right==NULL)){return 0;}
    
    if(root->vc!=0){return root->vc;}

    int incl = 1; // including current node
    incl+=vertex_cover(root->left)+vertex_cover(root->right);

    int excl=0;  // excluding current node but including their childs
    if(root->left){
        excl+=1+vertex_cover(root->left->left)+vertex_cover(root->left->right); // including child
    }
    if(root->right){
        excl+=1+vertex_cover(root->right->left)+vertex_cover(root->right->right); // including child
    }

    root->vc = min(incl, excl);
    return root->vc;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    node *root                = newNode(20); 
    root->left                = newNode(8); 
    root->left->left          = newNode(4); 
    root->left->right         = newNode(12); 
    root->left->right->left   = newNode(10); 
    root->left->right->right  = newNode(14); 
    root->right               = newNode(22); 
    root->right->right        = newNode(25);
    
    cout<<vertex_cover(root)<<"\n";

    return 0;
}