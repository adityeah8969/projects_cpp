#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int get_lis(int arr[], int n){

    int dp[n+5];
    for(int i=0;i<=n;i++){dp[i]=1;}

    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
    }

    int maxi = 1;
    for(int i=0;i<n;i++){maxi = max(maxi, dp[i]);}

    return maxi;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int arr[] = {3, 10, 2, 1, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<get_lis(arr,n);

    return 0;
}