#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void coin_change(int arr[], int m , int sum){

    int ways[sum+5];
    for(int i=0;i<=sum;i++){ways[i]=0;}
    sort(arr,arr+m);
    ways[0]=1;

    for(int i=0;i<m;i++){
        for(int j=arr[i];j<=sum;j++){
            ways[j]+=ways[j-arr[i]];
        }
    }
    cout<<ways[sum]<<"\n";
    return;
}

int main(){

    int arr[] = {1,2,3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int sum = 4;
    coin_change(arr,m,sum);

    return 0;
}