#include<bits/stdc++.h>
using namespace std;


void pre_order_util(int in[], int post[], unordered_map<int, int> index_map, int left, int right, int *post_index, stack<int>* pre_order){
    
    if(left>right){return;}
    
    int curr = post[*post_index];
    *post_index = *post_index - 1;
    int in_index = index_map[curr];
    
    pre_order_util(in, post, index_map, in_index+1, right, post_index, pre_order);
    pre_order_util(in, post, index_map, left, in_index-1, post_index, pre_order);
    
    pre_order->push(curr);
    
    return;
}


void print_preorder(int in[], int post[], int n){
    
    unordered_map<int, int> index_map;
    for(int i=0;i<n;i++){
        index_map[in[i]] = i;
    }
    
    stack<int> pre_order;
    
    int post_index = n-1;
    pre_order_util(in, post, index_map, 0, n-1, &post_index, &pre_order);
    
    while(!pre_order.empty()){
        cout<<pre_order.top()<<" ";
        pre_order.pop();
    }
    
    return;
}

int main(){
    
    int in[] = { 4, 10, 12, 15, 18, 22, 24, 25, 31, 35, 44, 50, 66, 70, 90 };
    int post[] = { 4, 12, 10, 18, 24, 22, 15, 31, 44, 35, 66, 90, 70, 50, 25 };
    int n = sizeof(post)/sizeof(post[0]);
     
    print_preorder(in, post, n);
    return 0;
}