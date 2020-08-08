#include <bits/stdc++.h>

using namespace std;
list <int>Adj[100];
int n;
int distX[100];
int distY[100];
int mateX[100];
int mateY[100];			// O(E*sqrt(V))

void resetDist(){
	for(int i=1;i<=n;i++){
		distX[i]=0;
		distY[i]=0;
	}
	return;
}

void resetMate(){
	for(int i=1;i<=n;i++){
		mateX[i]=-1;
		mateY[i]=-1;
	}
	return;
}

// checking if augmenting path with start vertex 'u' exists or not using distX & distY.
// setting up mateX & mateY recursively
bool dfs(int u){
	
	for(auto it=Adj[u].begin();it!=Adj[u].end();it++){
		int v=*(it);
		if(distY[v]==distX[u]+1){
			distY[v]=0;							//* frees v from getting selected again
		    if(mateY[v]==-1 || dfs(mateY[v])){
	   	  	   mateX[u]=v;
	   	  	   mateY[v]=u;
	   	  	   return true;
			 }	
		}
	}
	
	return false;
}

// checking if any augmenting pth exists. If yes then setting up distX,distY for retracing later.
bool bfs(){
    
	bool found=false;
	queue<int> Q;
	
	for(int i=1;i<=n;i++){
		if(mateX[i]==-1){
			Q.push(i);
		}
	}
	
	resetDist();
	
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		
		for(auto it=Adj[u].begin();it!=Adj[u].end();it++){
			int v=*(it);
			// distY[v]>0 suggests having a mateY[v]!=-1 or already having a mate in X side set in the surrent bfs()
			// distY[v]==0 can still means that it can have a mate in X set cz of resetDist() called prior to while loop
			if(distY[v]==0){
				distY[v]=distX[u]+1;
				if(mateY[v]==-1){found=true;}
				else{
					distX[mateY[v]]=distY[v]+1;
					Q.push(mateY[v]);
				}
			}
		}
		
	}
	return found;
}

int hopcroftKarp(){
	
	int res=0;
	
	while(bfs()){
		for(int i=1;i<=n;i++){
			if(mateX[i]==-1){
				if(dfs(i)){res++;}
			}
		}	
	}
    return res;	
}

void addEdge(int a,int b){
    Adj[a].push_back(b);
    return;
}

int main(){

    n=8;
    addEdge(1, 6); 
    addEdge(1, 7); 
    addEdge(2, 5); 
    addEdge(3, 6); 
    addEdge(4, 6); 
    addEdge(4, 8);
    
    resetDist();
    resetMate();

    cout<<hopcroftKarp()<<"\n";

    return 0;
}