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

Node* findInorderRecursive(Node* root, Node* x)             // first find the node, then trace back and check if there was a parent node with a left child
{                                                           
    
    if (!root){return NULL;}
    if (root == x){return root;}                
    
    Node* temp_left =  findInorderRecursive(root->left, x);
    
    if(temp_left){
        cout<<root->data;
        return NULL;
    }
    
    Node* temp_right =  findInorderRecursive(root->right, x);
    return !(temp_right)? NULL: root;
}

void findInorderSuccessor(Node* root, Node* temp){
    
    if(!root || !temp){
        cout<<"invalid i/p";
        return;
    }
    
    cout<<"inorder successor of "<<temp->data<<" : ";
    
    if(temp->right){
        Node* ans = left_most(temp->right);
        cout<<ans->data<<"\n";
        return;
    }
    
    if(temp == right_most(root)){
        cout<<"no inorder successor\n";
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
    
    findInorderSuccessor(root, root);        
    findInorderSuccessor(root, root->left);  
    findInorderSuccessor(root, root->right);  
    findInorderSuccessor(root, root->left->left);
    findInorderSuccessor(root, root->left->right);
    findInorderSuccessor(root, root->right->left);
    findInorderSuccessor(root, root->right->right);

    return 0;
}
