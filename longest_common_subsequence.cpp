#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int get_lcs(string str1, string str2){

    int n = str1.length();
    int m = str2.length();

    str1 = '*' + str1;
    str2 = '*' + str2;

    int lcs[n+5][m+5];
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){lcs[i][j] = 0;}
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(str1[i] == str2[j]){lcs[i][j] = max(1+lcs[i-1][j-1], lcs[i][j]);}
            lcs[i][j] = max(lcs[i][j],max(lcs[i][j-1], lcs[i-1][j]));
        }
    }
    
    return lcs[n][m];
}

int main(){

    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";
    cout<<get_lcs(str1, str2)<<"\n";
    return 0;
}