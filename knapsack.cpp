#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int knapsack(int val[], int wt[], int W, int n){

    int dp[n+5][W+5];

    vector<int> value;
    vector<int> weight;

    value.push_back(-1);
    weight.push_back(-1);

    for(int i=0;i<n;i++){
        value.push_back(val[i]);
        weight.push_back(wt[i]);
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = 0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(j>=weight[i]){
                dp[i][j] = max(dp[i-1][j],value[i]+dp[i-1][j-weight[i]]);
            }
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
        }
    }

    return dp[n][W];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 

    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapsack(val,wt,W,n)<<"\n"; 

    return 0;
}