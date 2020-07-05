#include <bits/stdc++.h>
using namespace std;

class edge{
    public:
    int src;
    int dest;
    int weight;
};

edge* Edges=NULL;

int V,E;
int dist[100];


void BellmanFord(){

    for(int i=1;i<=V-1;i++){
        for(int j=0;j<E;j++){
            int u=Edges[j].src;
            int v=Edges[j].dest;
            int w=Edges[j].weight;
            if(dist[u]!=INT_MAX && dist[v] > dist[u]+w){
                dist[v]=dist[u]+w;
            }
        }
    }

    for(int j=0;j<E;j++){
            int u=Edges[j].src;
            int v=Edges[j].dest;
            int w=Edges[j].weight;
            if(dist[u]!=INT_MAX && dist[v] > dist[u]+w){
                cout<<"Negative weight cycle exixts!\n";
                return;
        }
    }

    cout<<"vertex   ---  distance\n";
    for(int i=0;i<V;i++){
        cout<<i<<"         "<<dist[i]<<"\n";
    }
    return;
}


void init(int src){
    for(int i=0;i<=V;i++){dist[i]=INT_MAX;}
    dist[src]=0;
    return;
}

int main(){
    V = 5;  // Number of vertices in graph 
    E = 8;  // Number of edges in graph 
    
    Edges=new edge[E];
  
    Edges[0].src = 0; 
    Edges[0].dest = 1;
    Edges[0].weight = -1; 

    Edges[1].src = 0; 
    Edges[1].dest = 2; 
    Edges[1].weight = 4; 

    Edges[2].src = 1; 
    Edges[2].dest = 2; 
    Edges[2].weight = 3; 

    Edges[3].src = 1; 
    Edges[3].dest = 3; 
    Edges[3].weight = 2; 

    Edges[4].src = 1; 
    Edges[4].dest = 4; 
    Edges[4].weight = 2; 

    Edges[5].src = 3; 
    Edges[5].dest = 2; 
    Edges[5].weight = 5; 

    Edges[6].src = 3; 
    Edges[6].dest = 1; 
    Edges[6].weight = 1; 

    Edges[7].src = 4; 
    Edges[7].dest = 3; 
    Edges[7].weight = -3; 
    
    int src=0;
    init(src);
    BellmanFord(); 
    return 0;
}
