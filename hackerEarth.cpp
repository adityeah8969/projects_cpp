#include <bits/stdc++.h>
using namespace std;
vector<long long int> vec;
vector<long long int> segment_tree[4*1000005];


vector<long long int> query(int low,int high,int qs,int qe,int i){

    if(qs>high || qe<low || low>high){vector<long long int> t; return t;}
    if(qs<low && qe>high){return segment_tree[i];}
    int mid=low+(high-low)/2;
    vector<long long int> left=query(low,mid,qs,qe,2*i+1);
    vector<long long int> right=query(mid+1,high,qs,qe,2*i+2);
    int len=left.size()+right.size()-2;
    vector<long long int> temp(len);
    merge(left.begin(),left.end(),right.begin(),right.end(),temp.begin());
    return temp;

}


vector<long long int> merger(vector<long long int> a,vector<long long int> b){
    int len=a.size()+b.size()-2;
    vector<long long int> t(len);
    merge(a.begin(),a.end(),b.begin(),b.end(),t.begin());
    return t;
}


void build(int low,int high,int i){
    if(low==high){
        segment_tree[i].push_back(vec[low]);
        cout<<"\n"<<i<<"\n";
        cout<<"\n";
        return;
    }
    int mid=low+(high-low)/2;
    build(low,mid,2*i+1);
    build(mid+1,high,2*i+2);
    segment_tree[i]=merger(segment_tree[2*i+1],segment_tree[2*i+2]);
    return;
}
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    
    long long int a;
    for(int i=1;i<=n;i++){
        cin>>a;
        vec.push_back(a);
    }
    build(0,n-1,0);
    long long int ans=0;
    int len=vec.size()-1;
    // for(int i=1;i<=len-1;i++){
    //     vector<long long int> leftVec=query(0,n-1,0,i-1,0);
    //     vector<long long int> rightVec=query(0,n-1,i+1,n-1,0);
    //     long long int left=upper_bound(leftVec.begin(),leftVec.end(),vec[i])-leftVec.begin();
    //     long long int right=upper_bound(rightVec.begin(),rightVec.end(),vec[i])-rightVec.begin();
    //     ans+=(left*right);
    // }
    cout<<ans<<"\n";
    return 0;
}