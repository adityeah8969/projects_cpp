#include <bits/stdc++.h>
using namespace std;


const int MAX=100005;
int n;
int maxHeight;

list<int>Adj[MAX];
bool visited[MAX];
int level[MAX];
int parent[MAX];
int dp[MAX][50];

void addEdge(int u,int v){
    Adj[u].push_back(v);
    Adj[v].push_back(u);
    return;
}

void dfs(int u){
    int v;
    for(auto it=Adj[u].begin();it!=Adj[u].end();it++){
        v=*it;
        if(!visited[v]){
            visited[v]=true;
            level[v]=level[u]+1;
            maxHeight=max(level[v],maxHeight);
            parent[v]=u;
            dfs(v); 
        }
    }
    return;
}


void init(){
    maxHeight++;
    for(int i=0;i<n+1;i++){
        parent[i]=-1;
        for(int j=0;(1<<j)<=maxHeight;j++){
            dp[i][j]=-1;
        }
    }
    return;
}

void preProcess(){

    for(int i=1;i<=n;i++){
        dp[i][0]=parent[i];
    }
    
    for(int j=1;(1<<j)<=maxHeight;j++){  
        for(int i=1;i<=n;i++){
            if(dp[i][j-1]!=-1){
                dp[i][j]=dp[dp[i][j-1]][j-1];
            }
        }
    }
    
    return;
}

int LCA(int x,int y){
    
    if(level[x]<level[y]){swap(x,y);}
    int dist=level[x]-level[y];

    while(dist>0){
        int raise=log2(dist);
        x=dp[x][raise];
        dist-=(1 << raise);
    }
    
    if(x==y){return x;}
    
    for(int i=maxHeight;i>=0;i--){
        if(dp[x][i]!=-1 && (dp[x][i]!=dp[y][i])){
            x=dp[x][i];
            y=dp[y][i];
            break;
        }    
    }
    
    return parent[x];
    
}

void show(){
    
    for(int i=0;i<=n;i++){
        cout<<i<<": ";
        for(int j=0;j<=5;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    return;
}


int main(){
    
    n=13;
    
    addEdge(1,2);
    addEdge(1,3);
    addEdge(1,4);
    addEdge(2,5);
    addEdge(3,6);
    addEdge(4,7);
    addEdge(6,8);
    addEdge(6,9);
    addEdge(7,10);
    addEdge(7,11);
    addEdge(10,12);
    addEdge(10,13);
    
    visited[1]=true;
    init();
    dfs(1);
    preProcess();

    cout<<"(11,12): "<<LCA(11,12)<<"\n";
    cout<<"(10,6) : "<<LCA(10,6) <<"\n";
    cout<<"(8,9)  : "<<LCA(8,9)  <<"\n";
    cout<<"(10,13): "<<LCA(10,13)<<"\n";
    cout<<"(5,9)  : "<<LCA(5,9)  <<"\n";

    return 0;
}