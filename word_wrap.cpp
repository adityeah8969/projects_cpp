#include<bits/stdc++.h>
using namespace std;

#define ll long long int


int word_wrap(int l[], int n, int M){

    int spaces[n+5][n+5];
    int dp[n+5][n+5];
    int c[n+5];

    vector<int> words;
    words.push_back(-1);

    for(int i=1;i<=n;i++){
        spaces[i][i] = M - words[i];
        for(int j=i+1;j<=n;j++){
            spaces[i][j] = spaces[i][j-1] - words[j] -1;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(spaces<0){dp[i][j] = 0;}
            else{dp[i][j] = spaces[i][j]*spaces[i][j];}
        }
    }

    c[0] = 0;
    for(int j=1;j<=n;j++){
        c[j] = INT_MAX;

        for(int i=1;i<=j;i++){
            if(c[i-1]!=INT_MAX && dp[i][j]!=INT_MAX && c[i-1]+dp[i][j]<c[j]){
                c[j] = c[i-1]+dp[i][j];
            }
        }

    }
    return c[n];
}



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l[] = {3, 2, 2, 5};
    int n = sizeof(l)/sizeof(l[0]);
    int M=6;

    cout<<word_wrap(l, n, M);
    
    return 0;
}