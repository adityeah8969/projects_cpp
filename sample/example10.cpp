#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;

    ll a[n+5],b[m+5];

    for(int i=n;i>=1;i--){cin>>a[i];}
    for(int i=m;i>=1;i--){cin>>b[i];}

    ll x[n+5];
    int prev = 0;
    bool inco = false;

    for(int i=1;i<=m;i++){
        if(inco){break;}
        ll temp = b[i];
        for(int j=prev+1;j<=n;j++){
            if(a[j]<temp || (j==n && a[j]!=temp)){
                inco = true;
                break;
            }
            if(a[j]==temp){
                x[i] = j;
                prev = j;
                break;
            }
        }
    }
    
    if(inco){cout<<0<<"\n";return 0;}

    vector<int> vec;
    int count;
    for(int i=1;i<m;i++){
        count = 0;
        int index = x[i];
        while(a[index]>=b[i] && index<=n){
            count++;
            index++;
        }
        vec.push_back(count);
    }


    ll ans =1LL;
    for(int i=0;i<vec.size();i++){
        ans*=vec[i];
    }

    cout<<ans<<"\n";
    return 0;
}