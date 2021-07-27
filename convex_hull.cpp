#include <bits/stdc++.h>
using namespace std;

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
    return a.x < b.x;
}

bool cw(point a, point b, point c){                     // upper half
    point ab = point(b.x-a.x, b.y-a.y);
    point bc = point(c.x-b.x, c.y-b.y);
    int cross_product = ab.x*bc.y - bc.x*ab.y;
    return  cross_product<0;
}

bool ccw(point a, point b, point c){                    // lower half
    point ab = point(b.x-a.x, b.y-a.y);
    point bc = point(c.x-b.x, c.y-b.y);
    int cross_product = ab.x*bc.y - bc.x*ab.y;
    return  cross_product>0;
}

void graham_scan_convex_hull(vector<point> vec){
    
    sort(vec.begin(), vec.end(), cmp);
    int n =vec.size();
    point p1 =vec[0];
    point p2 = vec[n-1];
    
    vector<point> up, down;
    up.push_back(p1);
    down.push_back(p1);
    
    for(int i=1;i<n;i++){
        
        point curr = vec[i];
        
        if(i==n-1 || cw(p1, curr, p2)){
            int len = up.size();
            while(len>=2 && !cw(up[len-2], up[len-1], curr)){ up.pop_back(); len--;}
            up.push_back(curr);
        }
        
        if(i==n-1 || ccw(p1, curr, p2)){
            int len = down.size();
            while(len>=2 && !ccw(down[len-2], down[len-1], curr)){ down.pop_back(); len--;}
            down.push_back(curr);
        }
        
    }
    
    int u_len = up.size();
    int d_len = down.size();

    
    for(int i=0;i<u_len;i++){cout<<up[i].x<<", "<<up[i].y<<"\n";}   
    for(int i=d_len-2;i>0;i--){cout<<down[i].x<<", "<<down[i].y<<"\n";}             // ignoring p1 & p2

    return;
}

int main() {
    
    vector<point> vec={{0, 3}, {1, 1}, {2, 2}, {4, 4}, 
                      {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    graham_scan_convex_hull(vec);
    
    return 0;
}