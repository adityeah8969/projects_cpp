#include <bits/stdc++.h>
using namespace std;



#define V 4 
int dist[100][100];

void FloydWarshall(int graph[][V]){

    int dist[V][V];

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            dist[i][j]=graph[i][j];
        }
    }

    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][k]+dist[k][j] < dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }


    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            
            if(dist[i][j]==INT_MAX){cout<<"INF  ";}
            else
            cout<<dist[i][j]<<"  ";
        }
        cout<<"\n";
    }

    return;
}

int main(){


     int graph[V][V] = { {0, 5, INT_MAX, 10},  
                        {INT_MAX, 0, 3, INT_MAX},  
                        {INT_MAX, INT_MAX, 0, 1},  
                        {INT_MAX, INT_MAX, INT_MAX, 0}  
     };  
     
     FloydWarshall(graph);
     return 0;
}