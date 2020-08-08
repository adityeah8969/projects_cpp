#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define M 1000005

int tree[M];

void init(){
    for(int i=0;i<M;i++){tree[i] = -1;}
    return;
}

bool is_leftmost(int i){
    int r=0;                                        // * start from root
    while(tree[r]!=-1){r = 2*r+1;}
    r=(r-1)/2;
    return r==i;
}

int nearest_parent_with_right_child(int i, int p){
    if(i == 2*p+2){return p;}
    return nearest_parent_with_right_child(p, (p-1)/2);
}

int rightmost_child(int i){
    while(tree[r]!=-1){r = 2*r+2;}
    r=(r-1)/2;
    return r;
}

int inorder_predecessor(int i){

    int ans = -1;
    if(tree[2*i+1]==-1){
        if(is_leftmost(i)){
            cout<<"no predecessor found\n";
            return ans;
        }
        else{
            ans = nearest_parent_with_right_child(i, (i-1)/2);
        }
    }
    else{
        ans = rightmost_child(2*i+1);
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
    cout<<inorder_predecessor(2)<<"\n";
    cout<<inorder_predecessor(4)<<"\n";
    cout<<inorder_predecessor(5)<<"\n";

    return 0;
}

//         0
//     1       2
//   3   4    5 