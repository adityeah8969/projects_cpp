#include<bits/stdc++.h>
using namespace std;

#define ll long long int


// in general dp[i][j] should be dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]
// in case str[i] == str[j] we have to add all the subsequences which starts from i & end at j i.e 1+dp[i+1][j-1]

int palindromic_subsequences(string str){

    int n = str.length();
    int dp[n+5][n+5];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){dp[i][j] = 0;}
    }

    for(int i=0;i<n;i++){
        dp[i][i]=1;
        dp[i][i+1]=2;
        if(i+1<n && str[i]==str[i+1]){dp[i][i+1]++;}
    }

    int j;
    for(int l=2;l<n;l++){
        for(int i=0i<n;i++){
            j=i+l;
            dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
            if(str[i]==str[j]){
                dp[i][j] += 1 + dp[i+1][j-1];
            }
        }
    }

    return dp[0][n-1];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string str = "abcb";
    cout<<palindromic_subsequences(str);

    return 0;
}