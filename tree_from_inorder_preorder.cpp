#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define M 1000005

char arr[M];

static int k =0;

void construct_tree(string in, string pre, int l, int r,int root){

    if(r==l){
        arr[root] = in[l];
        return;
    }

    arr[root] = pre[k];
    
    int mid=-1;
    for(int i=l;i<=r;i++){
        if(in[i]==pre[k]){
            mid = i;
            break;
        }
    }
    
    if(mid-1>=l){
        ++k;
        construct_tree(in, pre, l, mid-1, 2*root+1);
    }
    if(r>= mid+1){
        ++k;
        construct_tree(in, pre, mid+1, r, 2*root+2); 
    }
    
    return;
}

void show_tree(){

    for(int i=0;i<=10;i++){
        cout<<arr[i]<<" ";
    }

    return;
}

int main(){

    string in = "DBEAFC";
    string pre = "ABDECF";  

    int n = in.length();
    construct_tree(in, pre, 0, n-1, 0);

    show_tree();

    return 0;
}

// D B E A F C  in
// 0 1 2 3 4 5
// A B D E C F  pre