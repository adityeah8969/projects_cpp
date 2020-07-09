#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define M 200005

list<int> Adj[M];
bool visited[M], is_articulationPoint[M];
int parent[M];
int low[M], disc[M];  // low[i] holds the least discovery time of all the nodes of the subtree rooted at 'i'.
int times;

void addEdge(int u, int v){
    Adj[u].push_back(v);
    Adj[v].push_back(u);
    return;
}

void init(){
    for(int i=0;i<M;i++){
        Adj[i].clear();
        visited[i] = false;
        parent[i] = -1;
        low[i] = 0;
        disc[i] = 0;
    }
    times = 0;
    return;
}

void set_articulation_points(int u){

    int childs = 0;
    visited[u] = true;
    disc[u] = low[u] = ++times;

    for(auto it=Adj[u].begin();it!=Adj[u].end();it++){
        int v = *it;
        if(!visited[v]){
            childs++;
            parent[v] = u;
            set_articulation_points(v);
            low[u] = min(low[u], low[v]);

            // root having more than 1 child
            if(parent[u] == -1 && childs>1){is_articulationPoint[u] = true;} 

            // if the low time of any of the descendant is less than the discovery time  of its parent(current node), 
            // then it  assures the presence of a back edge and thereby nullifying the possibility of (current node) 
            // being an articulation point. 
            // (low[v]<disc[u]) is the condition for the above statement
            // !(low[v]<disc[u]) to make it an articulation point
            if(parent[u] != -1 && !(low[v]<disc[u])){is_articulationPoint[u] = true;}
        }
        else
        if(parent[u]!=v){
            // low[u] picking up the lowest dicovery time amongst visited descendants.
            low[u] = min (low[u], disc[v]);
        }

    }

}

void show_articulation_points(){
    cout<<"Articulation points: ";
    for(int i=0;i<M;i++){
        if(is_articulationPoint[i]){cout<<i<<" ";}
    }
    cout<<"\n";
    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(1, 7); 
    addEdge(2, 3);
    addEdge(2, 4);
    addEdge(4, 5);
    addEdge(4, 6);

    set_articulation_points(0);
    show_articulation_points();

    return 0;
}