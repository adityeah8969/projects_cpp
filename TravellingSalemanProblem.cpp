#include <bits/stdc++.h>
using namespace std;

int n=4;
int dp[17][5];

int dist[10][10] = {
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
};


int visited_all=(1<<n)-1;

// Hamiltonian cycle: A graph cycle (i.e., closed loop) through a graph that visits each node exactly once.

// tsp(mask, pos) or dp[mask][pos] stores the minimum weight hamiltonian cycle to be achieved from the current state
// of already covered nodes (mask) which includes current node(pos).
int tsp(int mask,int pos){

    if(mask==visited_all){return dist[pos][0];}
        
    if(dp[mask][pos]!=-1){return dp[mask][pos];}

    int ans=INT_MAX;

    for(int city=0;city<n;city++){
            if((mask & (1<<city))==0){
                int newAns=dist[pos][city]+tsp(mask|(1<<city) ,city);
                ans=min(ans,newAns);
            }
    }
    return dp[mask][pos]=ans;
}

void init(){
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            dp[i][j]=-1;
        }
    }
    return;
}

int main(){
    init();
    cout<<" Minimum weight hamiltonian cycle(TSP): " <<tsp(1,0)<< "\n";               //*
    return 0;
}
