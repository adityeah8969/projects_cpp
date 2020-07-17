#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define M 1000005

static int k;
int post[M];

void construct_postorder(int in[], int pre[], int low, int high, int root_index){
    
    int root = pre[root_index];
    post[k] = root;

    int mid;
    for(int i=low;i<=high;i++){
        if(in[i] == root){
            mid = i;
            break;
        }
    }

    int left_nodes = (mid - low);

    if(high>=mid+1){
        k--;
        construct_postorder(in, pre, mid+1, high, root_index+left_nodes+1);
    }
    if(low<=mid-1){
        k--;
        construct_postorder(in, pre, low, mid-1, root_index+1);
    }
    return;
}

void show_postorder(int n){
    for(int i=0;i<5*n;i++){cout<<post[i]<<" ";}
    return;
}

int main(){

    int in[] = {4, 2, 5, 1, 3, 6};
    int pre[] = {1, 2, 4, 5, 3, 6};

    int n = sizeof(in)/sizeof(in[0]);
    k = n-1;
    construct_postorder(in, pre, 0, n-1, 0);
    show_postorder(n);

    return 0;
}