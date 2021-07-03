#include<bits/stdc++.h>
using namespace std;

#define pp pair<int, int>

const int M = 100;
const int MAXI = 100000;

vector<pp> Adj[M];
int dist[M];
priority_queue<pp, vector<pp>, greater<pp>> pq;

void init(int src){
    for(int i=0;i<M;i++){
        dist[i] = MAXI;
        Adj[i].clear();
    }
    while(!pq.empty()){pq.pop();}
    dist[src] = 0;
    return;
}

void add_edge(int u, int v, int w){
    Adj[u].push_back({v, w});
    Adj[v].push_back({u, w});
    return;
}

void display_dist(int V){
    for(int i=0;i<V;i++){cout<<i<<"--->"<<dist[i]<<"\n";}
    return;
}

void dijkstras(int src, int V){
    pq.push({dist[src], src});
    int counter = 1;

    while(!pq.empty()){                                     // O(V) -> considering every vertex will be added to the path only once, when they get popped out of the heap for the first time.
        int u = pq.top().second;                            // having a counter to make sure the loop braks after V iterations.
        if(counter > V){break;}                             
        counter++;
        pq.pop();                                           // O(logE) =O(logV)
        int w;
        for(auto it=Adj[u].begin();it!=Adj[u].end();it++){  // O(Ev)
            int v = it->first;
            int w = it->second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});                      // O(logV)
            }
        }
    }
    return;
}

int main(){
    int V=9;
    
    init(0);
    
    add_edge(0, 1, 4); 
    add_edge(0, 7, 8); 
    add_edge(1, 2, 8); 
    add_edge(1, 7, 11); 
    add_edge(2, 3, 7); 
    add_edge(2, 8, 2); 
    add_edge(2, 5, 4); 
    add_edge(3, 4, 9); 
    add_edge(3, 5, 14); 
    add_edge(4, 5, 10); 
    add_edge(5, 6, 2); 
    add_edge(6, 7, 1); 
    add_edge(6, 8, 6); 
    add_edge(7, 8, 7);
    
    dijkstras(0, V);
    
    display_dist(V);
    
    return 0;
}

// Time Complexity: O(V)*(O(1)+O(logV)+O(Ev*logV)) = O(VEv*logV) = O(ElogV)