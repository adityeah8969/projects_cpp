#include <bits/stdc++.h>
using namespace std;

#define level 20

const int N=100005;
vector<int> Adj[N];
int depth[N];
bool visited[N];
int parent[N];
int dp[N][level];


void addEdge(int i,int j){
    Adj[i].push_back(j);
    Adj[j].push_back(i);
}


void dfs(int src){
    
    for(auto it=Adj[src].begin();it!=Adj[src].end();it++){
        int v=*it;
        if(!visited[v]){
            depth[v]=1+depth[src];
            visited[v]=true;
            parent[v]=src;
            dfs(v);
        }
    }
    return;
}

void preCompute(){
    
    for(int i=1;i<N;i++){dp[i][0]=parent[i];}
    
    for(int j=1;j<level;j++){
        for(int i=1;i<N;i++){
            if(dp[i][j-1]!=-1){
                dp[i][j]=dp[dp[i][j-1]][j-1];        // 2^jth ancestor of i will be 2^(j-1)th ancestor of (2^(j-1)th ancestor of i)
            }
        }
    }

    return;
}

int LCA(int u,int v){
    
    if(depth[u]>depth[v]){swap(u,v);}
    int height=depth[v]-depth[u];
    
    for(int i=0;i<=level;i++){
        if((height>>i)&1){
            v=dp[v][i];                             // raising v to the same level as u
        }
    }


    if(u==v){return u;}
    
    for(int i=level-1;i>=0;i--){
        if(dp[u][i]!=-1 && dp[u][i]!=dp[v][i]){     // let 2^kth ancestor be LCA(u,v). Ancestors above 2^kth ancestorlevel will also have the equality dp[u][i]==dp[v][i] true.
            u=dp[u][i];                             // so we are looking for the level where we hit dp[u][i]!=dp[v][i] first. After wich we set u and v to dp[u][i] , dp[v][i]
            v=dp[v][i];                             // respectively. The outer loop ends with u & v being just below LCA.
        }
    }
    
    return dp[u][0];
}


void init(){
    
    for(int i=0;i<N;i++){
        visited[i]=false;
        parent[i]=i;
        depth[i]=0;
    }
    
    for(int i=0;i<N;i++){
        for(int j=0;j<=level;j++){dp[i][j]=-1;}
    }
    
    return;
}

int main() {
    
    
    addEdge(1,2); 
    addEdge(1,3); 
    addEdge(2,4); 
    addEdge(2,5); 
    addEdge(2,6); 
    addEdge(3,7); 
    addEdge(3,8);
    
    init();
    
    int src=1;
    depth[src]++;
    parent[src]=-1;
    visited[src]=true;
    dfs(src);                   // to compute depth and parent
    
    preCompute();
    
    cout<<LCA(4,7)<<"\n";
    cout<<LCA(4,6)<<"\n";
    
    return 0;
}




