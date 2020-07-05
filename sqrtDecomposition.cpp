#include <bits/stdc++.h>
using namespace std;
const int MAX=100005;
int n;

int arr[MAX];
int blockArr[1005];
int blockSize;


void update(int index,int val){
    int i=index/blockSize;
    blockArr[i]+=(val-arr[index]);
    arr[index]=val;
    return;
}

long long int query(int l,int r){

    long long int sum=0;

    while(l<r && l%blockSize!=0 && l!=0){
        sum+=arr[l];
        l++;
    }

    while(l+blockSize<=r){
        sum+=blockArr[l/blockSize];
        l+=blockSize;
    }

    while(l<=r){
        sum+=arr[l];
        l++;
    }

    return sum;
}

void preProcess(int input[]){

    blockSize=sqrt(n);
    int blockIndex=-1;

    for(int i=0;i<n;i++){
        arr[i]=input[i];
        if(i%blockSize==0){blockIndex++;}
        blockArr[blockIndex]+=arr[i];
    }

    return;
}



int main(){

    int input[] = {5,9,7,8,11,78,3,6,2,7,12,35,47,18,99,101};

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
    return 0;
}