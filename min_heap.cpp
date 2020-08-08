#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define M 100005

int min_heap[M];
int heap_size;

void insert_key(int key){
    if(heap_size == 0){min_heap[heap_size++] = key; return;}
    min_heap[heap_size++] = key;
    int i = heap_size-1;
    while(i>0){
        if(min_heap[(i-1)/2]>min_heap[i]){swap(min_heap[(i-1)/2], min_heap[i]);}
        i = (i-1)/2;
    }
    return;
}

void heapify(int i){
    
    int min_index;
    int mini = INT_MAX;
    while(i<heap_size){
        min_index = -1;
        if(2*i+1 < heap_size){mini = min_heap[2*i+1];min_index = 2*i+1;}
        if(2*i+2 < heap_size  &&  min_heap[2*i+2]<mini){mini = min_heap[2*i+2];min_index = 2*i+2;}
        if(min_heap[i]<mini || min_index == -1){break;}
        swap(min_heap[i], min_heap[min_index]);
        i = min_index;
    }

    return;
}

int extract_min(){
    
    if(heap_size == 0){
        cout<<"no elements to return\n";
        return -1;
    }
    
    int ans = min_heap[0];
    min_heap[0] =  min_heap[heap_size-1];
    heap_size--;
    heapify(0);
    return ans;
}


void init(){
    for(int i=0;i<M;i++){min_heap[i] = INT_MAX;}
    return;
}


int main(){

    heap_size = 0;

    init();

    insert_key(3); 
    insert_key(2); 
    insert_key(15); 
    insert_key(5); 
    insert_key(4); 
    insert_key(45);


    cout<<extract_min();
    cout<<"\n";
    
    
    cout<<extract_min();
    cout<<"\n";
    
    return 0;
}