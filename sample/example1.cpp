#include <bits/stdc++.h>
using namespace std;

const int ln=16;
const int m=10005;

int n,chainId,pos;

vector<int> Adj[m],cost[m],indexx[m];
int depth[m],otherEnd[m],subSize[m],chainHead[m],chainPos[m],chainInd[m],baseArray[m],segmentTree[4*m];
int pa[m][ln];
bool visited[m],visited1[m];

void dfs(int u,int d){

    subSize[u]=1;

    for(int i=0;i<Adj[u].size();i++){
        int v=Adj[u][i];
        if(!visited[v]){
            depth[v]=d+1;
            visited[v]=true;
            otherEnd[indexx[u][i]]=v;
            pa[v][0]=u;
            dfs(v,depth[v]);
            subSize[u]+=subSize[v];
        }
    }

    return;
}


void LCA(){

    for(int j=1;j<ln;j++){
        for(int i=0;i<m;i++){
            if(pa[i][j-1]!=-1){
                pa[i][j]=pa[pa[i][j-1]][j-1];
            }
        }
    }

    return;
}

int computeLCA(int u,int v){

    if(depth[u]>depth[v]){swap(u,v);}
    int diffHeight=depth[v]-depth[u];
    for(int i=1;i<ln;i++){
        if(diffHeight & (1<<i)){v=pa[v][i];}
    }

    if(u==v){return u;}

    for(int i=ln-1;i>=0;i--){
        if(pa[u][i]!=-1 && pa[u][i]!=pa[v][i]){
            u=pa[u][i];
            v=pa[v][i];
        }
    }

    return pa[u][0];
}

void HLD(int u,int weight){

    if(chainHead[chainId]==-1){chainHead[chainId]=u;}

    chainInd[u]=chainId;
    chainPos[u]=pos;
    baseArray[pos]=weight;
    pos++;

    int tempNode=-1;
    int tempSubsetSize=-1;
    int tempWeight=-1;


    int v;
    for(int i=0;i<Adj[u].size();i++){
        v=Adj[u][i];
        if(!visited1[v] && subSize[v]>tempSubsetSize){
            tempNode=v;
            tempWeight=cost[u][i];
            tempSubsetSize=subSize[v];
        }
    }

    if(tempNode!=-1){
        visited1[v]=true;
        HLD(v,tempWeight);
    }

    int v1;
    for(int i=0;i<Adj[u].size();i++){
        v1=Adj[u][i];
        if(!visited1[v] && v1!=v){
            chainId++;
            visited1[v1]=true;
            HLD(v1,cost[u][i]);
        }
    }

    return;
}

void makeTree(int low,int high,int i){

    if(low==high){segmentTree[i]=baseArray[low];return;}

    int mid=low+(high-low)/2;
    makeTree(low,mid,2*i+1);
    makeTree(mid+1,high,2*i+2);
    segmentTree[i]=max(segmentTree[2*i+1],segmentTree[2*i+2]);

    return;
}

int query(int low,int high,int ss,int se,int i){
    if(se<low || ss>high || low>high){return 0;}
    if(ss<=low && se>=high){return segmentTree[i];}
    int mid=low+(high-low)/2;
    return max(query(low,mid,ss,se,2*i+1),query(mid+1,high,ss,se,2*i+2));
}

void update(int low,int high,int index,int val,int i){

    if(index<low || index>high || low>high){return;}

    if(low==high){
        baseArray[low]=val;
        segmentTree[i]=baseArray[low];
        return;
    }

    int mid=low+(high-low)/2;
    update(low,mid,index,val,2*i+1);
    update(mid+1,high,index,val,2*i+2);
    segmentTree[i]=max(segmentTree[2*i+1],segmentTree[2*i+2]);
    return;
}


int queryUp(int u,int v){

    int ans=-1;
    int uChain;
    int vChain=chainInd[v];

    while(true){
        uChain=chainInd[u];
        if(uChain==vChain){
            ans=max(ans,query(0,n-1,chainPos[u],chainPos[v]+1,0));
            break;
        }
        ans=max(ans,query(0,n-1,chainPos[u],chainPos[chainHead[uChain]]+1,0));
        u = chainHead[uChain];
        u = pa[u][0];
    }
    return ans;
}

int queryQ(int u,int v){
    int lca=computeLCA(u,v);
    return max(queryUp(u,lca),queryUp(v,lca));
}

void changeQ(int i,int val){
    int u=otherEnd[i];
    update(0,n-1,baseArray[u],val,0); // see +1
}


void init(){

// int n,chainId,pos;

// vector<int> Adj[m],cost[m],indexx[m];
// int depth[m],otherEnd[m],subSize[m],chainHead[m],chainPos[m],chainInd[m],baseArray[m],segmentTree[4*m];
// int pa[m][ln];
// bool visited[m],visited1[m];

    for(int i=0;i<=n;i++){
        chainId=0;
        pos=0;
        Adj[i].clear();
        cost[i].clear();
        indexx[i].clear();
        depth[i]=0;
        otherEnd[i]=-1;
        subSize[i]=0;
        chainHead[i]=-1;
        chainPos[i]=-1;
        chainInd[i]=-1;
        baseArray[i]=-1;
        visited[i]=false;
        visited1[i]=false;
        for(int j=0;j<ln;j++){
            pa[i][j]=-1;
        }
    }

    for(int i=0;i<=4*n;i++){
        segmentTree[i]=-1;
    }

    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        
        cin>>n;
        init();

        int u,v,w;
        for(int i=0;i<n;i++){
            cin>>u>>v>>w;

            u--;
            v--;

            Adj[u].push_back(v);
            Adj[v].push_back(u);

            otherEnd[u]=v;
            otherEnd[v]=u;

            cost[u].push_back(w);
            cost[v].push_back(w);

            indexx[u].push_back(i);
            indexx[v].push_back(i);
        }

        int src=0;
        visited[src]=true;
        depth[src]=0;
        pa[src][0]=-1;
        dfs(src,depth[src]);

        LCA();

        int tempWeight=-1;
        HLD(src,tempWeight); 


        while(true) {
			string s;
            cin>>s;
			if(s[0]=='D') {break;}
				
			int a, b;
			cin>>a>>b;

			if(s[0]=='Q') {
				cout<<queryQ(a-1, b-1)<<"\n";
			} else {
				changeQ(a-1, b);
			}
		}
    }

    return 0;
}
