#include<bits/stdc++.h>
using namespace std;

class node{
  
  public:
    int data;
    node* left;
    node* right;
    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    
};


node* construct_tree_util(int in[], int post[], int low, int high, int *post_index, unordered_map<int, int> index_map){
    
    if(low>high){return NULL;}
    
    int curr = post[*post_index];
    node* root = new node(curr);
    *post_index = *post_index - 1;
    
    if(low == high){return root;}
    
    int ind = index_map[curr];
    
    root->right = construct_tree_util(in, post, ind+1, high, post_index, index_map);
    root->left = construct_tree_util(in, post, low, ind-1, post_index, index_map);
    
    return root;
}


node* construct_tree(int in[], int post[], int n){
    
    unordered_map<int, int> index_map;
    for(int i=0;i<n;i++){ index_map[in[i]] = i; }
    
    int post_index = n-1;
    return construct_tree_util(in, post, 0, n-1, &post_index, index_map);
}


void print_inorder(node* root){
    if(!root){return;}
    if(root->left){print_inorder(root->left);}
    cout<<root->data<<" ";
    if(root->right){print_inorder(root->right);}
    return;
}


int main ()
{
    int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
    int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
    int n = sizeof(in) / sizeof(in[0]);
 
    node* root = construct_tree(in, post, n);
 
    cout << "Preorder of the constructed tree : ";
    print_inorder(root);
 
    return 0;
}

//           1
//       /      \
//      2         3
//    /    \    /   \
//   4      5  6     7
//     \
//       8
