#include <bits/stdc++.h>
using namespace std;

bool wildcard_matching(string text, string pattern){
    
    int n = text.length();
    int m = pattern.length();
    
    bool dp[n+1][m+1];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j] = false;
        }
    }
    
    dp[0][0] = true;
    
    for(int j=1;j<=m;j++){
        if(pattern[j-1]=='*'){                      // empty string can be matched by '*'.
            dp[0][j] = dp[0][j-1];                 
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(pattern[j-1]=='*'){
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
            else
            if(pattern[j-1]=='?' || text[i-1]==pattern[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
}

int main() {
    string text = "baaabab";
    string pattern = "*****ba*****ab";
    cout<<wildcard_matching(text, pattern);
    return 0;
}