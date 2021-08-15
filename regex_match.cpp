#include <bits/stdc++.h>
using namespace std;

bool regexMatch(string s, string p) {
    
    int n = s.length();
    int m = p.length();
    
    bool dp[n+1][m+1];
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = false;
        }
    }
    
    dp[0][0] = true;                                                // empty pair of strings match
    
    for(int i=1;i<=m;i++){
        if(p[i-1] == '*'){
            dp[0][i] = dp[0][i-2];                                  // patterns like a*, a*b*, a*b*c* etc, will all match with empty strings
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(p[j-1] == '.' || p[j-1] == s[i-1]){                  // cases where ith character of 's' matches with jth of 'p'
                dp[i][j] = dp[i-1][j-1];
            }
            else
            if (p[j-1] == '*') {
                dp[i][j] = dp[i][j-2];                              // cases where 0 occurences of character before '*' had to be matched.
                if(s[i-1] == p[j-2] || p[j-2] == '.'){              // making sure that jth pattern previous to '*' in 'p' is the same as the ith of 's'
                    dp[i][j] = dp[i][j] || dp[i-1][j];              // dp[i-1][j] is used in RHs, and not dp[i-1][j-1] because '*' can match with next
                                                                    // set of potentially same characters. e.g, asume j = 2, i = 4 in the following
                }                                                   // ab*
                                                                    // abbbb
            }                                                       // if we use dp[i-1][j-1] here, dp[3][1] (false) then it will lead to insconsistent results 
            else{
                dp[i][j] = false;
            }
        }
    }
    
    return dp[n][m];
}

int main() {
    
    string s, p; // str, pattern
    
    s = "aa";
    p = "a";
    cout<<regexMatch(s, p)<<"\n";
    
    s = "aa";
    p = "a*";
    cout<<regexMatch(s, p)<<"\n";
    
    s = "ab";
    p = ".*";
    cout<<regexMatch(s, p)<<"\n";
    
    s = "aab";
    p = "c*a*b";
    cout<<regexMatch(s, p)<<"\n";
    
    s = "mississippi";
    p = "mis*is*p*.";
    cout<<regexMatch(s, p)<<"\n";
    
    s = "aaa";
    p = "aaaa";
    cout<<regexMatch(s, p)<<"\n";
    
    return 0;
}

// Problem statement:

// Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

// '.' Matches any single character.​​​​
// '*' Matches zero or more of the preceding element.      
// The matching should cover the entire input string (not partial).

// e.g 

// s = "aab";
// p = "c*a*b";

// ans -> true
