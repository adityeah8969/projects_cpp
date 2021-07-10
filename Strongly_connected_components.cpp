#include <bits/stdc++.h>
using namespace std;

#define M 200005

list<int> Adj[M];             
list<int> rAdj[M];
bool visitedr[M];
bool visited[M];
int order[M];
int tracker;
stack<int>S;


void addEdge(int a,int b){
    Adj[a].push_back(b);
    rAdj[b].push_back(a);
    return;
}

void kosaraju_pass1(int u){
    for(auto it=rAdj[u].begin();it!=rAdj[u].end();it++){                // pass1 on reversed edges
        int v=*it;
        if(!visitedr[v]){visitedr[v]=true;kosaraju_pass1(v);}
    }
    order[tracker++]=u;                                                 // order[] stores the discovery time in reverse 
    return;                                                             // order.
}

void kosaraju_pass2(int u){
    for(auto it=Adj[u].begin();it!=Adj[u].end();it++){
        int v=*it;
        if(!visited[v]){visited[v]=true;kosaraju_pass2(v);}
    }
    S.push(u);
    return;
}

void init(){
    for(int i=0;i<M;i++){
        visitedr[i]=false;
        visited[i]=false;
        Adj[i].clear();
        rAdj[i].clear();
        order[i]=0;
    }
    tracker=1;                                                  //*
    while(!S.empty()){S.pop();}
    return;
}

void print_scc(){
    while(!S.empty()){
        cout<<S.top()<<" ";
        S.pop();
    }
    return;
}

int main(){
    
    init();
    const int N = 5;
    addEdge(1, 0); 
    addEdge(0, 2); 
    addEdge(2, 1); 
    addEdge(0, 3); 
    addEdge(3, 4); 
    
    for(int i=0;i<N;i++){
        if(!visitedr[i]){
            visitedr[i]=true;
            kosaraju_pass1(i);
        }
    }
    // kosaraju_pass1(0);
    int strongly_connected_components=0;
    cout<<"Following are the SCCs: \n";
    for(int i=N;i>=1;i--){                                  // traversing through the order[] in reverse order
        int u=order[i];                                     // i.e recent discovery first
        if(!visited[u]){
              visited[u]=true;
              kosaraju_pass2(u);
              strongly_connected_components++;              // *
              print_scc();
              cout<<"\n";
        }
    }
    cout<<"total no. of SCCs are: "<<strongly_connected_components;
    return 0;
}
