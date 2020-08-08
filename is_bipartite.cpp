#include <bits/stdc++.h>
using namespace std;

#define V 4

int G[][V] = {      {0, 1, 0, 1},                   //* declaration
                    {1, 0, 1, 0}, 
                    {0, 1, 0, 1}, 
                    {1, 0, 1, 0} 
             }; 
             
int color[V+5];

bool is_bipartite(int src){
    
    for(int i=0;i<=V;i++){color[i]=-1;}
    color[src] = 1;

    queue<int> q;
    q.push(src);
    
    while(!q.empty()){
        
        int u = q.front();
        q.pop();

        for(int v=0;v<V;v++){

            if(G[u][v] && color[v] == -1){
                color[v] = 1 - color[u];
                q.push(v);
            }

            if(G[u][v] && color[v] == color[u]){
                return false;
            }
        }  
    }
    
    return true;
}

int main() {
    cout<<"The given graph is bipartite --> ";
    is_bipartite(0)?cout<<"Yes":cout<<"No";
    return 0;
}