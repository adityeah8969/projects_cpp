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


node* construct_tree_util(int in[], int pre[], int low, int high, int *pre_index, unordered_map<int, int> index_map){
    
    if(low>high){return NULL;}
    
    int curr = pre[*pre_index];
    node* root = new node(curr);
    *pre_index = *pre_index + 1;
    
    if(low == high){return root;}
    
    int ind = index_map[curr];
    
    root->left = construct_tree_util(in, pre, low, ind-1, pre_index, index_map);
    root->right = construct_tree_util(in, pre, ind+1, high, pre_index, index_map);

    return root;
}


node* construct_tree(int in[], int pre[], int n){
    
    unordered_map<int, int> index_map;
    for(int i=0;i<n;i++){ index_map[in[i]] = i; }
    
    int pre_index = 0;
    return construct_tree_util(in, pre, 0, n-1, &pre_index, index_map);
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
    int in[] = { 4, 2, 5, 1, 6, 3 };
    int pre[] = { 1, 2, 4, 5, 3, 6 };
    int len = sizeof(in) / sizeof(in[0]);
    node* root = construct_tree(in, pre, len);
    cout << "Inorder traversal of the constructed tree is \n";
    print_inorder(root);
}

//         1
//       /   \
//      /     \
//     2       3
//   /  \      /
//  /    \    /
// 4      5  6
