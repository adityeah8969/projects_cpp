#include <iostream>
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

Node* left_most(Node* root){
    while(root && root->left){
        root = root->left;
    }
    return root;
}

Node* right_most(Node* root){
    while(root && root->right){
        root = root->right;
    }
    return root;
}

Node* findInorderRecursive(Node* root, Node* x)             // first find the node, then trace back and check if there was a parent node with a right child
{                                                           
    
    if (!root){return NULL;}
    if (root == x){return root;}                

    Node* temp_right =  findInorderRecursive(root->right, x);

    if(temp_right){
        cout<<root->data;
        return NULL;
    }
    
    Node* temp_left =  findInorderRecursive(root->left, x);
    
    return !(temp_left)? NULL: root;
}

void findInorderPredecessor(Node* root, Node* temp){
    
    if(!root || !temp){
        cout<<"invalid i/p";
        return;
    }
    
    cout<<"inorder predecessor of "<<temp->data<<" : ";
    
    if(temp->left){
        Node* ans = right_most(temp->left);
        cout<<ans->data<<"\n";
        return;
    }
    
    if(temp == left_most(root)){
        cout<<"no inorder predecessor\n";
        return;
    }
    
    findInorderRecursive(root, temp);
    cout<<"\n";
    return;
}

int main() {
    
    // Let's construct the binary tree 
    //       1
    //    /    \
    //   2      3
    //  / \    / \
    // 4   5  6   7
    
    Node* root          = new Node(1);
    root->left          = new Node(2);
    root->right         = new Node(3);
    root->left->left    = new Node(4);
    root->left->right   = new Node(5);
    root->right->left   = new Node(6);
    root->right->right  = new Node(7);
    
    findInorderPredecessor(root, root);        
    findInorderPredecessor(root, root->left);  
    findInorderPredecessor(root, root->right);  
    findInorderPredecessor(root, root->left->left);
    findInorderPredecessor(root, root->left->right);
    findInorderPredecessor(root, root->right->left);
    findInorderPredecessor(root, root->right->right);

    return 0;
}
