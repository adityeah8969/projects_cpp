#include<bits/stdc++.h>
using namespace std;

#define ll long long int

// Observation 1:
// The problem is not actually to find the critical floor, but merely to decide floors from which eggs 
// should be dropped so that the total number of trials are minimized.
// minimum worst case trials

// Observation 2:
// Because the question has nothing to do with finding the critical height, for a certain contiguous chunk
// of floors (chunk size) and a certain number of eggs the answer will remain the same irrespective of
// the location (or altitude) of contiguous chunk.
// i.e say there is a building of height 50 (floors), if we consider a series(or chunk) of 4 floors and 
// 1 number of eggs, it does not matter whether the series of floors are (2->5) or (10->13) or (45->48)
// etc, as the minimum number of worst case trials would continue to be 4 (with number of eggs being 1).

// Observation 3:
// In the previous observation we can infer that if we have 1 egg then the minimum worst case trial would be 
// the number of floors, because we have individually check if the egg breaks from the certain floor.
// But in case we have more than 1 egg then we can be aggressive with our search i.e instead of picking the
// first floor to start with we can pick a somewhere in between first and top floor and proceed.
// The innermost loop in the silution is doing the exact smae thing by considering all the intermediate 
// (bottom to top) floors as the starting floor.

// Observation 4:
// If the egg breaks from a certain height, then we dont have to bother looking at heights above
// otherwise we have to check for heights above.
// 1(current trial)    +   max(    dp[i-1][x-1],   dp[i][j-x])
//                                   egg broke,      egg did not break
//                     1 egg less & 1 floor less, same number of eggs & only the chunk of floors above


int egg_drop(int n, int k){

    int dp[n+5][k+5];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j] = INT_MAX;
        }
    }

    for(int i=1;i<=n;i++){dp[i][0]=0;dp[i][1]=1;}
    for(int i=1;i<=k;i++){dp[1][i]=i;}

    for(int i=2;i<=n;i++){
        for(int j=2;j<=k;j++){
            for(int x=1;x<=j;x++){                
                dp[i][j] = min(dp[i][j], 1+max(dp[i-1][x-1], dp[i][j-x]));
            }
        }
    }

    return dp[n][k];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 2;
    int k = 36;
    cout<<"Minimum number of worst case trials with "<<n<<" eggs and "<<k<<" floors: "<<egg_drop(n,k)<<"\n";

    return 0;
}