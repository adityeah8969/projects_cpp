#include <iostream>
#include <list>
using namespace std;

list<int>Adj[10];
int parent[10];
int N;


void init(){

    for(int i=1;i<=N;i++){
        Adj[i].clear();
        parent[i]=-1;
    }

    return;
}

void dfs(int u, int p){

    int v;
    for(auto it=Adj[u].begin();it!=Adj[u].end();it++){
        v=*it;
        if(v!=p){
            parent[v]=u;
            dfs(v,parent[v]);
        }
    }
    return;
}


void addEdge(int u,int v){
    Adj[u].push_back(v);
    Adj[v].push_back(u);
    return;
}

void display(){
    for(int i=1;i<=5;i++){
        cout<<parent[i]<<"-->"<<i<<"\n";
    }
    return;
}

int main(){

    init();

    N=5;

    addEdge(1,2);
    addEdge(1,3);
    addEdge(2,4);
    addEdge(2,5);
    // addEdge(4,5);                           // this edge creates a cycle, commenting this out will lead to stack overflow 

    dfs(1,-1);
    display();

    return 0;
}