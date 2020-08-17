#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define M 1000005

int arr[M];

static int k =0;

void construct_tree(int in[], int post[], int l, int r, int root){

    // if(r==l){
    //     arr[root] = in[l];
    //     return;
    // }

    arr[root] = post[k];
    
    int mid=-1;
    for(int i=l;i<=r;i++){
        if(in[i]==post[k]){
            mid = i;
            break;
        }
    }
    
    if(r >= mid+1){
        --k;
        construct_tree(in, post, mid+1, r, 2*root+2); 
    }
    if(mid-1 >= l){
        --k;
        construct_tree(in, post, l, mid-1, 2*root+1);
    }
    
    return;
}

void show_tree(){
    for(int i=0;i<=10;i++){cout<<arr[i]<<" ";}
    return;
}

int main(){

    int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 }; 
    int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 }; 

    int n = sizeof(in)/sizeof(in[0]);
    k = n-1;
    construct_tree(in, post, 0, n-1, 0);

    show_tree();

    return 0;
}
