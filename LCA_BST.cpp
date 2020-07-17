#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define M 100005

int bst[M];

void init(){
    for(int i=0;i<M;i++){bst[i] = -1;}
    return;
}

int lca(int u, int v){

    int root = 0;

    while(root!=-1){

        if(u<bst[root] && v<bst[root]){root = 2*root+1;}
        if(u>bst[root] && v>bst[root]){root = 2*root+2;}
        else{break;}

    }

    return root==-1?-1:bst[root];
}

int main(){

    init();
    
    bst[0] = 20;
    bst[1] = 8;
    bst[2] = 22;
    bst[3] = 4;
    bst[4] = 12;
    bst[5] = 10;
    bst[6] = 14;

    cout<<lca(10, 14)<<"\n";
    cout<<lca(14, 8)<<"\n";
    cout<<lca(10, 22)<<"\n";


    return 0;
}