#include <iostream>
#include <list>
#include <stack>
using namespace std;

list<int> Adj[105];             //*
bool visited[105];
stack<int>S;
int N=6;

void addEdge(int a,int b){
    Adj[a].push_back(b);
    // Adj[b].push_back(a);
    return;
}


void topo_util(int u){

    for(auto it=Adj[u].begin();it!=Adj[u].end();it++){
        int v=*it;
        if(!visited[v]){visited[v]=true;topo_util(v);}
    }
    S.push(u);
    return;
}

void topo(){

    for(int i=0;i<N;i++){visited[i]=false;}
    for(int i=0;i<N;i++){if(!visited[i]){visited[i]=true;topo_util(i);}}
    while(!S.empty()){
        cout<<S.top()<<" ";
        S.pop();
    }
    return;
}


int main(){

    addEdge(5, 2); 
    addEdge(5, 0); 
    addEdge(4, 0); 
    addEdge(4, 1); 
    addEdge(2, 3); 
    addEdge(3, 1);

    topo();

    return 0;
}