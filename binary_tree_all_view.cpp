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

void printLeftView(Node* root){

    cout<<"left view: ";
    
    if(root == NULL){
        cout<<"no elements inside\n";
        return;
    }
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        
        Node* curr = q.front();
        cout<<curr->data<<" ";
        
        int n = q.size();
        
        for(int i=1;i<=n;i++){
            
            Node* temp = q.front(); 
            
            if(temp->left){
                q.push(temp->left);
            }
            
            if(temp->right){
                q.push(temp->right);
            }
            
            q.pop();
        }
    }
    cout<<"\n";
    return;
}

void printRightView(Node* root){

    cout<<"right view: ";
    
    if(root == NULL){
        cout<<"no elements inside\n";
        return;
    }
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        
        Node* curr = q.back();
        cout<<curr->data<<" ";
        
        int n = q.size();
        
        for(int i=1;i<=n;i++){
            
            Node* temp = q.front(); 
            
            if(temp->left){
                q.push(temp->left);
            }
            
            if(temp->right){
                q.push(temp->right);
            }
            
            q.pop();
        }
    }
    cout<<"\n";
    return;
}

void spriralOrderPrint(Node* root){

    cout<<"spriral order traversal: \n";
    
    if(root == NULL){
        cout<<"no elements inside\n";
        return;
    }
    
    deque<Node*> q;                                                 // queue will always have the elements from left to right. 
    q.push_back(root);                                              // Just that there printing will happen in spriral fashion.
    
    cout<<root->data<<"\n";
    
    bool left_to_right = false;
    
    while(!q.empty()){
        
        int n = q.size();
        
        for(int i=1;i<=n;i++){
            if(left_to_right){

                Node* curr = q.front();
                q.pop_front();
                
                if(curr->left){
                    cout<<curr->left->data<<" ";
                    q.push_back(curr->left);
                }
                if(curr->right){
                    cout<<curr->right->data<<" ";
                    q.push_back(curr->right);
                }
            }
            else{
                
                Node* curr = q.back();
                q.pop_back();
                
                if(curr->right){
                    cout<<curr->right->data<<" ";
                    q.push_front(curr->right);
                }
                
                if(curr->left){
                    cout<<curr->left->data<<" ";
                    q.push_front(curr->left);
                }
            }
        }
        left_to_right = !left_to_right;
        cout<<"\n";
    }
    return;
}

bool is_key(int key, map<int, Node*> m){
    return m.find(key)!=m.end();
}

void top_view(Node* root){

    cout<<"top view : ";

    if(root == NULL){
        cout<<"no elements inside\n";
        return;
    }
    
    map<int, Node*> top_view;
    queue<pair<Node*, int>> q;
    
    top_view[0] = root;
    q.push({root, 0});
    
    while(!q.empty()){
        
        pair<Node*, int> pp = q.front();
        q.pop();
        
        Node* curr = pp.first;
        int d = pp.second;
        
        if(curr->left){
            q.push({curr->left, d-1});
            if(!is_key(d-1, top_view)){
                top_view[d-1] = curr->left;
            }
        }
        
        if(curr->right){
            q.push({curr->right, d+1});
            if(!is_key(d+1, top_view)){
                top_view[d+1] = curr->right;
            }
        }
        
    }
    for(auto it=top_view.begin(); it!=top_view.end();it++){
        cout<<it->second->data<<" ";
    }
    cout<<"\n";
    return;
}

void bottom_view(Node* root){               // Assumption: If there are multiple bottom-most nodes from a horizontal distance from root, then print the later one in level traversal.
                                            // e.g 8 and 12 in the tree.

    cout<<"bottom view: ";

    if(root == NULL){
        cout<<"no elements inside\n";
        return;
    }

    map<int, Node*> bottom_view;
    queue<pair<Node*, int>> q;
    
    bottom_view[0] = root;
    q.push({root, 0});
    
    while(!q.empty()){
        
        pair<Node*, int> pp = q.front();
        q.pop();
        
        Node* curr = pp.first;
        int d = pp.second;
        
        if(curr->left){
            q.push({curr->left, d-1});
            bottom_view[d-1] = curr->left;
        }
        
        if(curr->right){
            q.push({curr->right, d+1});
            bottom_view[d+1] = curr->right;
        }
        
    }
    
    for(auto it=bottom_view.begin(); it!=bottom_view.end();it++){
        cout<<it->second->data<<" ";
    }
    cout<<"\n";
    return;
    
}

int main() {
    
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(8);
    root->right->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right->left = new Node(14);
 
    printLeftView(root);
    printRightView(root);
    top_view(root);
    bottom_view(root);
    spriralOrderPrint(root);
    
    return 0;
}

//           10
//     2             3
// 7      8     12       15
//                   14
