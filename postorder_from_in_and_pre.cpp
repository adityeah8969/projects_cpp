#include<bits/stdc++.h>
using namespace std;


void printPostOrder(int in[], int pre[], unordered_map<int, int> index_map, int left, int right, int *pre_index){
    
    if(left>right){return;}
    
    int curr = pre[*pre_index];
    *pre_index = *pre_index + 1;
    int in_index = index_map[curr];
    
    printPostOrder(in, pre, index_map, left, in_index-1, pre_index);
    printPostOrder(in, pre, index_map, in_index+1, right, pre_index);
    
    cout<<curr<<" ";
    
    return;
}


void postOrderUtil(int in[], int pre[], int n){
    
    unordered_map<int, int> index_map;
    for(int i=0;i<n;i++){
        index_map[in[i]] = i;
    }
    
    int pre_index = 0;
    printPostOrder(in, pre, index_map, 0, n-1, &pre_index);
    
    return;
}

int main(){
    
    int in[] = { 4, 2, 5, 1, 3, 6 };
    int pre[] = { 1, 2, 4, 5, 3, 6 };
    int n = sizeof(pre)/sizeof(pre[0]);
     
    postOrderUtil(in, pre, n);
    return 0;
}