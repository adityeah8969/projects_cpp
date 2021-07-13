#include<bits/stdc++.h>
using namespace std;

const int n = 100;
const int k = 100; 

int dp[n+1][k+1];

int knapsack(int val[], int wt[], int W, int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0){dp[i][j] = 0;}
            else
            if(j>=wt[i-1]){
                dp[i][j] = max(dp[i-1][j] , val[i-1]+dp[i-1][j-wt[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main(){
    
    int val[] = { 60, 100, 120 }; 
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 

    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapsack(val,wt,W,n)<<"\n"; 

    return 0;
}
