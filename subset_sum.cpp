#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int lcs(string a, string b){

    int n = a.length();
    int m = b.length();

    a = '*' + a;
    b = '*' + b;

    int lcs[n+5][m+5];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            lcs[i][j]=0;
        }
    }

    if(a[1] == b[1]){lcs[1][1]=1;}

    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            if(a[i] == b[j]){
                lcs[i][j] = max(lcs[i][j], 1+lcs[i-1][j-1]);
            }
            lcs[i][j] = max(lcs[i][j], max(lcs[i][j-1], lcs[i-1][j]));
        }
    }

}


int main(){

    
    return 0;
}