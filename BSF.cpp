#include<bits/stdc++.h>
using namespace std;

const int M = 100;
vector<int> Adj[M];
bool visited[M];
int parent[M];


void init(){
    for(int i=0;i<M;i++){
        visited[i]=false;
        parent[i]=-1;
        Adj[i].clear();
    }
    return;
}

void bfs(queue<int> Q){
    while(!Q.empty()){                                              // O(V)
        int u = Q.front();                                          // O(1)
        Q.pop();
        int v;
        for(auto it=Adj[u].begin();it!=Adj[u].end();it++){          // O(Expetcted Adjacent Edge) or O(Eaj)
            v = *it;
            if(!visited[v]){
                parent[v]=u;
                visited[v]=true;
                Q.push(v);
            }
        }
        
    }
    return;
}

void bfs_util(int V){
    for(int i=1;i<=V;i++){
        if(!visited[i]){
            visited[i]=true;
            queue<int> Q;
            Q.push(i);
            bfs(Q);
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
    add_edge(4,5);
    
    bfs_util(V);
    display(V);
    return 0;
}


// Time Complexity:
// O(V) * (O(1) + O(Eaj))   ->   O(E)
// Note: The actual complexity is O(E + V) considering 'bfs_util' method , with complexity O(V),
// might run extensilvely in case V >> E. So O(V + E) gives the best out of both worlds.