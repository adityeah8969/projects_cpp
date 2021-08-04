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


node* construct_tree_util(int pre[], int post[], int low, int high, int *pre_index, unordered_map<int, int> post_map, int size){
    
    if(low>high){return NULL;}

    int curr = pre[*pre_index];
    node* root = new node(curr);
    *pre_index = *pre_index + 1;                // make sure this gets incremented right after root node creation.

    if(low == high){return root;}
    
    int post_index, next_data;
    next_data = pre[*pre_index];
    post_index = post_map[next_data];
    
    root->left = construct_tree_util(pre, post, low, post_index, pre_index, post_map, size);
    root->right = construct_tree_util(pre, post, post_index+1, high-1, pre_index, post_map, size);
    
    return root;
}


node* construct_tree(int pre[], int post[], int n){
    unordered_map<int, int> post_map;
    for(int i=0;i<n;i++){ post_map[post[i]] = i; }
    int pre_index = 0;
    return construct_tree_util(pre, post, 0, n-1, &pre_index, post_map, n);
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
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int size = sizeof( pre ) / sizeof( pre[0] );
    
    node *root = construct_tree(pre, post, size);
 
    cout<<"Inorder traversal of the constructed tree: ";
    print_inorder(root);
 
    return 0;
}

//           1
//         /   \
//       2       3
//     /  \     /  \
//    4    5   6    7
//   / \  
//  8   9 
