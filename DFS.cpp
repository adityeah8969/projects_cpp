#include<bits/stdc++.h>
using namespace std;

const int M = 100;
vector<int> Adj[M];
int parent[M];

void init(){
    for(int i=0;i<M;i++){
        parent[i]=-1;
        Adj[i].clear();
    }
    return;
}

void dfs(int u, int p){
    int v;
    for(auto it=Adj[u].begin();it!=Adj[u].end();it++){
        v = *it;
        if(v != p){
            parent[v] = u;
            dfs(v, u);
        }
    }    
    return;
}

void dfs_util(int V){
    for(int i=1;i<=V;i++){
        if(parent[i]==-1){
            dfs(i, -1);    
        }
    }
    return;
}

void add_edge(int u, int v){
    Adj[u].push_back(v);
    Adj[v].push_back(u);
    return;
}

void display(int V){
    for(int i=1;i<=V;i++){cout<<parent[i]<<"--->"<<i<<"\n";}
    return;
}

int main(){
    int V=5;
    
    init();
    
    add_edge(1,2);
    add_edge(1,3);
    add_edge(2,4);
    add_edge(2,5);
    // add_edge(4,5);                       // cyclic graph, if uncommented
    
    dfs_util(V);
    
    display(V);
    return 0;
}