#include<bits/stdc++.h>
using namespace std;

#define ll long long int

bool wildcart_matching(string text, string pattern){

    int n = text.length();
    int m = pattern.length();

    text = '*' + text;
    pattern = '*' + pattern;

    bool dp[n+5][m+5];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = false;
        }
    }

    dp[0][0]=true;
    int start = 1;
    while(pattern[start]=='*'){
        dp[0][start] = true;
        start++;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(pattern[j] == '*'){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
            else
            if(pattern[j] == '?' || pattern[j] == text[i]){
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }

    return dp[n][m];
}

int main(){

    string text = "xyxzzxy";
    string pattern = "x***x?";

    cout<<wildcart_matching(text, pattern)<<"\n";

    return 0;
}