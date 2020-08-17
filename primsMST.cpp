#include <bits/stdc++.h>
using namespace std;

list<pair<int,int>> Adj[105];             
bool visited[105];
int N;
int key[105];
int parent[105];
bool mst[105];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

void addEdge(int u,int v,int w){
    Adj[u].push_back(make_pair(v,w));
    Adj[v].push_back(make_pair(u,w));
    return;
}

void init(int src){
    for(int i=0;i<N;i++){
        visited[i]=false;
        mst[i]=false;
        key[i]=INT_MAX;
        parent[i]=-1;
    }
    visited[src]=true;
    key[src]=0;
    mst[src]=true;
    return;
}

void primMst(int src){

    pq.push(make_pair(0,src));

    while(!pq.empty()){

        int u=pq.top().second;
        pq.pop();
        mst[u]=true;                                        //mst[u] gets true only after its proven that the vertex
                                                            //has been introduced via its least weight.
        for(auto it=Adj[u].begin();it!=Adj[u].end();it++){
            int v =(*it).first;
            int weight=(*it).second;
            if(!mst[v] && key[v]>weight){                   // we dont make mst[v] true inside because we want the 
                key[v]=weight;                              // pair having vertex 'v' get inside the priority queue
                parent[v]=u;                                // via some of its edges. Then picking the pair with least
                pq.push(make_pair(key[v],v));               // key[v] possible using priority queue.
                
            }
        }
    }

    cout<<"parent   ->   child\n";
    for(int i=1;i<N;i++){
        cout<<"  "<<parent[i]<<" ->   "<<i<<"\n";

    }
    return;
}


int main(){

    N=9;

    addEdge(0, 1, 4); 
    addEdge(0, 7, 8); 
    addEdge(1, 2, 8); 
    addEdge(1, 7, 11); 
    addEdge(2, 3, 7); 
    addEdge(2, 8, 2); 
    addEdge(2, 5, 4); 
    addEdge(3, 4, 9); 
    addEdge(3, 5, 14); 
    addEdge(4, 5, 10); 
    addEdge(5, 6, 2); 
    addEdge(6, 7, 1); 
    addEdge(6, 8, 6); 
    addEdge(7, 8, 7);

    int src=0;
    init(src);
    primMst(src);

    return 0;
}