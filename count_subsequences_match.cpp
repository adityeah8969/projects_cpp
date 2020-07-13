#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int count_subsequences_match(string text, string pattern){

    int n = text.length();
    int m = pattern.length();

    text = '*'+text;
    pattern = '*'+pattern;

    int dp[n+5][m+5];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = 0;
        }
    }

    for(int i=0;i<=n;i++){dp[i][0]=1;}

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]+=dp[i-1][j];               // excluding patern's last character 
            if(text[i] == pattern[j]){          // including pattern's last character
                dp[i][j] += dp[i-1][j-1];       // Note:  pattern's last character can be included only if it 
            }                                   // matches with text's last character
        }
    }

    return dp[n][m];
}

int main(){
    string text = "GeeksforGeeks";
    string pattern = "Gks";
    cout<<count_subsequences_match(text, pattern);
    return 0;
}