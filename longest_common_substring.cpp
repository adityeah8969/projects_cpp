#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int get_lcs(string str1, string str2){

    int n = str1.length();
    int m = str2.length();
    
    int dp[n+1][m+1];
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }   
    }

    return dp[n][m];
}

int main(){

    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";
    cout<<get_lcs(str1, str2)<<"\n";
    return 0;
}