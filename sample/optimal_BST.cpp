#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define M 2000005

int freq_sum[M];

void util(int freq[], int n){
    freq_sum[0] = freq[0];
    for(int i=1;i<n;i++){freq_sum[i] += freq[i]+freq_sum[i-1];}
    return;
}

int get_range_sum(int l, int r){
    int ans = 0;
    ans+=freq_sum[r];
    if(l>0){ans-=freq_sum[l-1];}
    return ans;
}

int optimal_BST_cost(int keys[], int freq[], int n){

    int dp[n+5][n+5];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = INT_MAX;
            if(i==j){
                dp[i][i] = freq[i];
            }
        }
    }

    for(int l=1;l<n;l++){
        for(int i=0;i+l<n;i++){
            int j = i+l;
            int freq_s = get_range_sum(i,j);
            for(int r=i;r<=j;r++){
                int temp_cost = 0LL;
                temp_cost+=r>i?dp[i][r-1]:0LL;
                temp_cost+=r<j?dp[r+1][j]:0LL;
                temp_cost+=freq_s;
                dp[i][j] = min(temp_cost, dp[i][j]);
            }
        }
    }

    return dp[0][n-1];

}

int main(){

    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};

    int n = sizeof(keys)/sizeof(keys[0]);
    util(freq, n);
    cout<<optimal_BST_cost(keys, freq, n);  

    return 0;
}