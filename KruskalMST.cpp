#include <bits/stdc++.h>
using namespace std;

class edge{
    public:
    int src;
    int dest;
    int weight;
};

vector<edge> result;

int E;
int V;
edge* Edges=NULL;

int parent[105];
int ranks[105];

int finds(int a){
    if(parent[a]!=a){parent[a] = finds(parent[a]);}     // *
    return parent[a];
}

void unions(int a,int b){

    a=finds(a);
    b=finds(b);

    if(ranks[a]>ranks[b]){
        parent[b]=a;
    }
    else
    {
        parent[a]=b;
        if(ranks[a]==ranks[b]){ranks[b]++;}
    }
    return;
}

bool comparator1(edge a,edge b){
    return (a.weight < b.weight);
}

void kruskalMST(){

    sort(Edges, Edges+E, comparator1);

    for(int i=0;i<E;i++){
        int a=Edges[i].src;
        int b=Edges[i].dest;

        int parentA=finds(a);
        int parentB=finds(b);

        if(parentA!=parentB){
            unions(parentA,parentB);
            result.push_back(Edges[i]);
        }
    }
    for(int i=0;i<result.size();i++){
        cout<<result[i].src<<"----->"<<result[i].dest<<"\n";
    }
    return;
}

void init(){
    for(int i=0;i<=V;i++){
        parent[i]=i;
        ranks[i]=1;
    }
    return;
}

int main(){

    V=4;
    E=5;
    Edges=new edge[5];
    
    Edges[0].src = 0;  
    Edges[0].dest = 1;  
    Edges[0].weight = 10;  


    Edges[1].src = 0;  
    Edges[1].dest = 2;  
    Edges[1].weight = 6;  


    Edges[2].src = 0;  
    Edges[2].dest = 3;  
    Edges[2].weight = 5;  

      
    Edges[3].src = 1;  
    Edges[3].dest = 3;  
    Edges[3].weight = 15;  

        
    Edges[4].src = 2;  
    Edges[4].dest = 3;  
    Edges[4].weight = 4;  

    init();
    kruskalMST();

    return 0;
}
// Time Complexity: O(ElogV)