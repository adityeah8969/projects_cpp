#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

#define V 6

bool bfs(int rGraph[V][V],int s,int t,int parent[]){

    bool visited[V];
    for(int i=0;i<V;i++){visited[i]=false;}

    queue<int>Q;
    visited[s]=true;
    Q.push(s);
    parent[s]=-1;

    while(!Q.empty()){

        int u=Q.front();
        Q.pop();

        for(int v=0;v<V;v++){
            if(visited[v]==false && rGraph[u][v] > 0){
                parent[v]=u;
                Q.push(v);
                visited[v]=true;
            }
        }
    }
    return (visited[t]==true);
}


int fordFulkerson(int graph[V][V],int s,int t){
    
    int rGraph[V][V];

 
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){rGraph[i][j]=graph[i][j];}
    }

    int parent[V];

    int max_flow=0;

    while(bfs(rGraph,s,t,parent)){

        int flow=INT_MAX;

        for(int v=t;v!=s;v=parent[v]){
            int u=parent[v];
            flow=min(flow,rGraph[u][v]);
        }

        for(int v=t;v!=s;v=parent[v]){
            int u=parent[v];
            rGraph[u][v]-=flow;
            rGraph[v][u]+=flow;
        }

        max_flow+=flow;
    }
    
    return max_flow;
}

int main(){

    int graph[V][V] = { {0, 16, 13, 0, 0, 0}, 
                        {0, 0, 10, 12, 0, 0}, 
                        {0, 4, 0, 0, 14, 0}, 
                        {0, 0, 9, 0, 0, 20}, 
                        {0, 0, 0, 7, 0, 4}, 
                        {0, 0, 0, 0, 0, 0} 
                      }; 
  
    cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5); 
  
    return 0; 
} 
