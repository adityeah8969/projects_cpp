#include <iostream>
#include <list>
#include <queue>
using namespace std;

list<int>Adj[10];
bool visited[10];
int parent[10];
int N;


void init(){

    for(int i=1;i<=N;i++){
        Adj[i].clear();
        visited[i]=false;
        parent[i]=-1;
    }

    return;
}



void bfs(list<int>Q){

    while(!Q.empty()){
        int u=Q.front();
        Q.pop_front();
        for(auto it=Adj[u].begin();it!=Adj[u].end();it++){
            int v=*it;
            if(!visited[v]){
                visited[v]=true;
                parent[v]=u;
                Q.push_back(v);
            }
        }
    }
    
    return;
}


void bfs_util(int u){

    for(int i=1;i<=N;i++){
        if(!visited[i]){
            list<int>Q;
            visited[i]=true;
            Q.push_back(i);
            bfs(Q);
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
    addEdge(4,5);

  
    bfs_util(1);
    display();

    return 0;
}