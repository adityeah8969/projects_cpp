#include<bits/stdc++.h>
using namespace std;

int get_lcs(string str1, string str2){

    int n = str1.length();
    int m = str2.length();

    int res=0;
    
    int dp[n+1][m+1];                   // dp[i][j] strores the logest common suffix of X[0..i-1] and Y[0..j-1] 
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){ dp[i][j] = 0;}
            else
            if(str1[i-1] == str2[j-1]){
                dp[i][j] =1+dp[i-1][j-1];
                res = max(res, dp[i][j]);
            }
            else{
                dp[i][j] = 0;
            }
            
        }
    }
    return res;
}

int main(){

    string str1 = "OldSite:GeeksforGeeks.org";
    string str2 = "NewSite:GeeksQuiz.com";
    cout<<get_lcs(str1, str2)<<"\n";
    return 0;
}