#include<bits/stdc++.h>
using namespace std;

#define ll long long int

// Reference
// https://cp-algorithms.com/geometry/grahams-scan-convex-hull.html#:~:text=The%20algorithm%20used%20here%20is,comparison%2C%20addition%20and%20multiplication%20operations.
// Time complexity : O(nlog(n))

class point{
    public:
    int x;
    int y;
    point(int a, int b){
        this->x = a;
        this->y = b;
    }
};

bool cmp(point a, point b){
    if(a.x == b.x){return a.y < b.y;}
    return (a.x < b.x);
}


bool cw(point a, point b, point c){
    point ab(b.x-a.x,b.y-a.y);
    point bc(c.x-b.x,c.y-b.y);
    int cross_product = ab.x*bc.y - ab.y*bc.x;
    return cross_product<0; 
}

bool ccw(point a, point b, point c){
    point ab(b.x-a.x,b.y-a.y);
    point bc(c.x-b.x,c.y-b.y);
    int cross_product = ab.x*bc.y - ab.y*bc.x;
    return cross_product>0; 
}

void graham_scan_convex_hull(vector<point> vec){

    sort(vec.begin(),vec.end(),cmp);
    point p1 = vec[0];
    int n = vec.size();
    point p2 = vec[n-1];

    vector<point> up, down;
    up.push_back(p1);
    down.push_back(p1);

    for(int i=1;i<n;i++){

        if(i==n-1 || cw(p1,vec[i],p2)){
            while(up.size()>=2 && !cw(up[up.size()-2], up[up.size()-1], vec[i])){up.pop_back();}
            up.push_back(vec[i]);
        }
        if(i==n-1 || ccw(p1,vec[i],p2)){
            while(down.size()>=2 && !ccw(down[down.size()-2], down[down.size()-1], vec[i])){down.pop_back();}
            down.push_back(vec[i]);
        }

    }

    int u_len = up.size();
    int d_len = down.size();

    for(int i=0;i<u_len;i++){cout<<up[i].x<<", "<<up[i].y<<"\n";}
    for(int i=d_len-2;i>0;i--){cout<<down[i].x<<", "<<down[i].y<<"\n";}  // * skipping both p1 & p2

    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    vector<point> vec={{0, 3}, {1, 1}, {2, 2}, {4, 4}, 
                      {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    graham_scan_convex_hull(vec);
    return 0;
}