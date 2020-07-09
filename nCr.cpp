#include<bits/stdc++.h>
using namespace std;

#define ll long long int
// #define M 1000*1000*1000+7
#define M 13

ll nCr(ll n, ll r){

    r = min(r,n-r);

    ll c[r+5];
    for(int i=0;i<=r;i++){c[i]=0LL;}

    c[0] =1LL;

    for(ll i=1;i<=n;i++){
        for(ll j=min(i,r);j>0;j--){
            c[j] = (c[j] + c[j-1])%M;
        }
    }
    return c[r];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n =10;
    ll r =2;
    cout<<nCr(n, r);

    return 0;
}