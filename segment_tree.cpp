#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define M 1000005

ll segment_tree[4*M];
ll arr[] = {1, 3, 5, 7, 9, 11}; 
ll lazy[4*M];

ll query(int qs, int qe, int low, int high, int i){

    if(lazy[i]!=0){
        segment_tree[i] += (high-low+1)*lazy[i];
        if(low!=high){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i] = 0LL;
    }

    if(qe<low || qs>high){return 0LL;}
    if(qs<=low && qe>=high){return segment_tree[i];}
    int mid = low+(high-low)/2;
    return query(qs,qe,low,mid,2*i+1) + query(qs,qe,mid+1,high,2*i+2);
}

void update(int qs, int qe, int low, int high, int i, ll diff){

    if(lazy[i]!=0){
        segment_tree[i] += (high-low+1)*lazy[i];
        if(low!=high){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i] = 0LL;
    }

    if(qe<low || qs>high){return;}

    if(qs<=low && qe>=high){
        segment_tree[i] += (high-low+1)*diff;
        if(low!=high){
            lazy[2*i+1]+=diff;
            lazy[2*i+2]+=diff;
        }
        return;
    }

    int mid = low + (high-low)/2;
    update(qs, qe, low, mid, 2*i+1, diff);
    update(qs, qe, mid+1, high, 2*i+2, diff);
    segment_tree[i] = segment_tree[2*i+1] + segment_tree[2*i+2];
    return;
}

void build(int low, int high, int i){

    if(low == high){
        segment_tree[i] = arr[low];
        return;
    }

    int mid = low +(high-low)/2;

    build(low, mid, 2*i+1);
    build(mid+1, high, 2*i+2);

    segment_tree[i] = segment_tree[2*i+1]+segment_tree[2*i+2];
    return;
}

int main(){

    int n= sizeof(arr)/sizeof(arr[0]);
    build(0,n-1,0);

    cout<<query(2, 4, 0, n-1,0)<<"\n";
    update(3,4,0,n-1,0,10);
    cout<<query(2, 4, 0, n-1,0)<<"\n";

    return 0;
}
