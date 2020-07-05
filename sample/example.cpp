#include<bits/stdc++.h>
using namespace std;

#define ll long long int

const int maxn = 100005;


ll arr[maxn];
ll narr[maxn];
ll parr[maxn];
ll sarr[maxn];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll ones = 1LL;
    ones<<=32;
    ones-=1;
    

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
        bitset<32> b(arr[i]);
        b.flip();
        narr[i]=b.to_ullong();
    }

    parr[0]=narr[0];
    for(int i=1;i<n;i++){
        parr[i]&=parr[i-1];
    }

    sarr[n-1]=narr[n-1];
    for(int i=n-2;i>=0;i--){
        sarr[i]&=sarr[i+1];
    }

    ll temp = -ones;
    int index=0;

    for(int i=0;i<n;i++){

        if(i==0){
            if(temp < arr[i]&sarr[i+1]){
                temp = arr[i]&sarr[i+1];
                index = i;
            }
            continue;
        }
        if(i==n-1){
            if(temp < arr[i]&parr[i-2]){
                temp = arr[i]&parr[i-2];
                index = i;
            }
            continue;
        }

        if(temp < arr[i]&parr[i-1]&sarr[i+1]){
                temp = arr[i]&parr[i-1]&sarr[i+1];
                index = i;
        }

    }

    cout<<arr[index]<<" ";
    for(int i=0;i<n;i++){
        if(i==index){continue;}
        cout<<arr[i]<<" ";
    }

    return 0;
}