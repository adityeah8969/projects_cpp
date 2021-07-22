#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int print_soln(int p[], int n){
    int k;
    if(p[n]==1){ k = 1; }
    else{ k = print_soln(p, p[n]-1) + 1; }
    cout<<"line "<<k<<": from "<<p[n]<<" to "<<n<<"\n";
    return k;
}

void solveWordWrap(int l[], int n, int m){
    
    int lc[n+1][n+1];
    int spaces[n+1][n+1];
    int dp[n+1];
    int p[n+1];
    
    for(int i=0;i<=n;i++){
        dp[i] = INF;
        for(int j=0;j<=n;j++){
          spaces[i][j] = INF;
          lc[i][j] = INF;
        }
    }
    
    for(int i=1;i<=n;i++){
        spaces[i][i] = m - l[i-1];
        for(int j=i+1;j<=n;j++){
            spaces[i][j] = spaces[i][j-1] - l[j-1] -1;
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(spaces[i][j]>0){lc[i][j] = spaces[i][j]*spaces[i][j];}
            else
            if(j==n && spaces[i][j]>=0){lc[i][j] = 0;}                  // spaces after including the last word getting ignored
            else
            if(spaces[i][j]<0){lc[i][j] = INF;}
        }
    }
    
    dp[0] = 0;
    for(int j=1;j<=n;j++){
        dp[j] = INF;
        for(int i=1;i<=j;i++){
            if(dp[i-1]!=INF && lc[i][j]!=INF && dp[j]>dp[i-1]+lc[i][j]){
                dp[j] = dp[i-1]+lc[i][j];
                p[j] = i;
            }
        }
    }
    
    int x = print_soln(p, n);
    return;
}

int main()
{
    int l[] = {3, 2, 2, 5};
    int n = sizeof(l)/sizeof(l[0]);
    int M = 6;
    solveWordWrap (l, n, M);
    return 0;
}
