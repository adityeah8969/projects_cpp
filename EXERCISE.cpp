#include <bits/stdc++.h>
using namespace std;

int N;
int arr[100005];
int mini[100005];
int maxi[100005];

int mx=1000000;

void init(){
  
  for(int i=1;i<=N;i++){
    if(arr[i]!=-1){
      mini[i]=arr[i];
      maxi[i]=arr[i];
    }
  }

  return;
}

bool constraint(int a,int b){
//   cout<<"  a:"<<a;
//   cout<<"  b:"<<b;
  
  return (b>=a && a>=0 && b<=mx);
}

void show(){
    
    
        
    for(int i=1;i<=N;i++){
        cout<<mini[i]<<" ";
    }
    cout<<"\n";
    for(int i=1;i<=N;i++){
        cout<<maxi[i]<<" ";
    }
    cout<<"\n";
    
    
    return;
}

int main(){
    
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T;
  cin>>T;

  while(T--){

    cin>>N;
    for(int i=1;i<=N;i++){cin>>arr[i];}
    string str;
    init();
    // show();
    // cout<<"\n";

    cin>>str;
    str="aa"+str;
    
    // cout<<str<<"\n";

    if(arr[1]==-1){
      mini[1]=0;
      maxi[1]=mx;
    }

    bool consistent=true;
    
    // show();
    // cout<<"\n";

    for(int i=2;i<=N;i++){
        
    // cout<<i<<" ";
    // cout<<"\n";

      if(str[i]=='>'){
        if(arr[i]!=-1 && mini[i]>=maxi[i-1]){
            // cout<<"v1\n";
          consistent=false;
          break;
        }
        if(arr[i]!=-1){continue;}
        mini[i]=0;
        maxi[i]=maxi[i-1]-1;
        if(!constraint(mini[i],maxi[i])){consistent=false;break;}
      }
      else
      if(str[i]=='<'){
        if(arr[i]!=-1 && mini[i]<=mini[i-1]){
            // cout<<"v3\n";
          consistent=false;
          break;
        }
        if(arr[i]!=-1){continue;}
        mini[i]=mini[i-1]+1;
        maxi[i]=mx;
        if(!constraint(mini[i],maxi[i])){consistent=false;break;}
      }
      else{
        if(arr[i]!=-1 && (mini[i]<mini[i-1] || mini[i]>maxi[i-1])){
            // cout<<"v5\n";
          consistent=false;
          break;
        }
        if(arr[i]!=-1){continue;}
        mini[i]=mini[i-1];
        maxi[i]=maxi[i-1];
      }

    }
    
    // show();

    if(consistent){cout<<"YES\n";}
    else{cout<<"NO\n";}
  
  }
  return 0;
}