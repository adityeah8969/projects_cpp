#include <bits/stdc++.h>
using namespace std;

#define p pair<long long int,pair<int,int>> 
#define p1 pair<long long int,int>

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    vector<long long int> l;
    vector<long long int> r;

    long long int a,b;
    for(int i=1;i<=n;i++){
        cin>>a>>b;                       // left and right end points of segments taken as input.
        l.push_back(a);
        r.push_back(b);
    }

    vector<p> seg;

    for(int i=1;i<=n-1;i++){
        seg.push_back({l[i],{-1,i}});    // seg will only store single end-point (either left or right) 
        seg.push_back({r[i],{1,i}});     // seg[i].second.first will determine which end point is it.
    }

    for(int i=1;i<=m;i++){
        cin>>a;                          // points taken as input, 
        seg.push_back({a,{0,i}});        // seg[i].second.first==0 says its a point
    }

    sort(seg.begin(),seg.end());         // sort 

    int ans[n+1];                        // ans[i] suggests ans[i] point got mapped to ith segment.

    for(int i=0;i<n;i++){ans[i]=-1;}

    set<p1> q;                          // we will consider the set of segments which a particular point can be in one 
                                        // at a time.

                                        


    int len=seg.size();
    int c;
    for(int i=0;i<len;i++){
        c=seg[i].second.first;
        int ind=seg[i].second.second;
        if(c==-1){ q.insert({r[ind],ind}); } // this will enforce right-end point to be inserted in the set
        else
        if(c==1){ q.erase({r[ind],ind}); }   // delete the right end-point as it cannot contain the upcoming point.
        else
        if(q.size()>0){                      // if q.size()>0 then the segment at top will definitely capture the point.
            int k=q.begin()->second;
            ans[k]=ind;
            q.erase(q.begin());
        }
    }

                                        // Also we will only consider the right-end point because of the following reason:
                                        // lets consider left-end point
                                        // Say the segments in the sorted order are {2,9}, {2,5}.... & points are 4,6 ..
                                        // 4 might get mapped to {2,9} leaving '6' unmapped.

    bool inc=false;

    for(int i=1;i<=n-1;i++){
        if(ans[i]==-1){
            cout<<"No\n";
            inc=true;
            break;
        }
    }

    if(!inc){ cout<<"Yes\n"; for(int i=1;i<=n-1;i++){cout<<ans[i]<<" ";} }
    
    return 0;
}