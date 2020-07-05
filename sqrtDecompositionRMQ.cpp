#include <bits/stdc++.h>
using namespace std;
const int MAX=100005;
int n;

int arr[MAX];
int blockArr[1005];
int blockSize;


void update(int index,int val){
    int i=index/blockSize;
    blockArr[i]=min(val,blockArr[i]);
    arr[index]=val;
    return;
}

int query(int l,int r){

    int mini=INT_MAX;

    while(l<r && l%blockSize!=0 && l!=0){
        mini=min(mini,arr[l]);
        l++;
    }

    while(l+blockSize<=r){
        mini=min(mini,blockArr[l/blockSize]);
        l+=blockSize;
    }

    while(l<=r){
        mini=min(mini,arr[l]);
        l++;
    }

    return mini;
}

void preProcess(int input[]){

    blockSize=sqrt(n);
    int blockIndex=-1;

    for(int i=0;i<n;i++){
        arr[i]=input[i];
        if(i%blockSize==0){blockIndex++;}
        blockArr[blockIndex]=min(blockArr[blockIndex],arr[i]);
    }

    return;
}



int main(){

    int input[] = {5,9,7,8,11,78,3,6,2,7,12,35,47,18,99,101};
    for(int i=0;i<1005;i++){blockArr[i]=INT_MAX;}
    n=sizeof(input)/sizeof(input[0]);
    preProcess(input);

    cout << "query(3,8) : " << query(3, 8)<<"\n"; 
    cout << "query(1,6) : " << query(1, 6)<<"\n"; 
    cout << "query(5,14) : " << query(5,14)<<"\n"; 
    cout << "query(6,11) : " << query(6,11)<<"\n"; 
    cout << "query(9,15) : " << query(9,15)<<"\n"; 
    cout << "query(3,14) : " << query(3,14)<<"\n"; 
    update(8, 0); 
    cout << "query(8,8) : " << query(8, 8) <<"\n"; 
    cout << "query(6,11) : " << query(6,11)<<"\n"; 
    return 0;
}