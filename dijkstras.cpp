#include <bits/stdc++.h>
using namespace std;

list<pair<int,int>> Adj[105];             
bool visited[105];
int N;
int dist[105];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

void addEdge(int u,int v,int w){
    Adj[u].push_back(make_pair(w,v));
    Adj[v].push_back(make_pair(w,u));
    return;
}

void dijkstras(int src){

    pq.push(make_pair(0,src));

    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        for(auto it=Adj[u].begin();it!=Adj[u].end();it++){
            int v=(*it).first;
            int weight=(*it).second;
            if(dist[v] > dist[u] + weight){
                dist[v]=dist[u]+weight;
                pq.push(make_pair(dist[v],v));
            }
        }
    }

    cout<<"vertex  -> distance\n";
    for(int i=0;i<N;i++){
        cout<<"   "<<i<<"    -> "<<dist[i]<<"\n";
    }

    return;
}

void init(int src){
    for(int i=0;i<=N;i++){dist[i]=INT_MAX;}
    dist[src]=0;
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

    init(0);
    dijkstras(0);

    return 0;
}
