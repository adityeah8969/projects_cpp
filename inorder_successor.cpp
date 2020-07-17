#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define M 1000005

int tree[M];

void init(){
    for(int i=0;i<M;i++){tree[i] = -1;}
    return;
}

bool right_most(int i){
    int r = 0;
    while(tree[r]!=-1 && tree[2*r+2]!=-1){r=2*r+2;}
    return r==i;
}

int nearest_parent_with_left_node(int i, int p){
    if(i == 2*p+1){return p;}
    return nearest_parent_with_left_node(p, (p-1)/2);
}   

int left_most(int r){
    while(tree[r]!=-1 && tree[2*r+1]!=-1){r = 2*r+1;}
    return r;
}

int inorder_successor(int i){
    int ans = -1;
    if(tree[2*i+2] == -1){
        if(right_most(i)){
            cout<<"no inorder successor \n";
            return ans;
        }
        ans = nearest_parent_with_left_node(i, (i-1)/2);
    }
    else{
        ans = left_most(2*i+2);
    }
    return ans;
}

int main(){

    init();

    tree[0] = 1;
    tree[1] = 2;
    tree[2] = 3;
    tree[3] = 4;
    tree[4] = 5;
    tree[5] = 6;

    // pass the index as parameter
    cout<<inorder_successor(2)<<"\n";
    cout<<inorder_successor(4)<<"\n";
    cout<<inorder_successor(5)<<"\n";

    return 0;
}

//         0
//     1       2
//   3   4    5 