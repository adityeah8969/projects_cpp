#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int matrix_multiplication(int arr[], int n){

    int dp[n+5][n+5];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = 0;
        }
    }

    for(int l=2;l<n;l++){
        for(int i=0;i<n;i++){
            int j = i+l;
            int c = INT_MAX;
            for(int k=i+1;k<j;k++){
                int temp = dp[i][k] + dp[k][j] + arr[i]*arr[j]*arr[k];
                c = min(c, temp);
            }
            dp[i][j] = c;
        }
    }
    return dp[0][n-1];
}

int main(){
    
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"minimum cost matrix chain multiolication: "<<matrix_multiplication(arr, n)<<"\n";

    return 0;
}