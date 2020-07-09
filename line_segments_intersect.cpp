#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pp pair<int, int>

int cross_product(pp a, pp b, pp c){

    pp ab = {b.first - a.first, b.second - a.second};
    pp bc = {c.first - b.first, c.second - b.first};

    int val = ab.first*bc.second - ab.second*bc.first;  // cross product

    if(val == 0){return val;}
    return val>0 ? 1:2;
}

bool on_segment(pp p1, pp q1, pp p2){
    return     p2.first <= max(p1.first, q1.first) && p2.first >= min(p1.first, q1.first)
           &&  p2.second <= max(p1.second, q1.second) && p2.second >= min(p1.second, q1.second);
}

bool intersects(pp p1, pp q1, pp p2, pp q2){

    int o1 = cross_product(p1, q1, p2);
    int o2 = cross_product(p1, q1, q2);
    int o3 = cross_product(p1, q1, p2);
    int o4 = cross_product(p1, q1, q2);

    if(o1!=o2 && o3!=o4){return true;}

    if(o1 == 0 && on_segment(p1, q1, p2)){return true;}
    if(o2 == 0 && on_segment(p1, q1, q2)){return true;}
    if(o3 == 0 && on_segment(p1, q1, p2)){return true;}
    if(o4 == 0 && on_segment(p1, q1, q2)){return true;}

    return false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pp p1,q1,p2,q2;

    p1 = {1, 1}, p2 = {1, 2};
    q1 = {10, 1},q2 = {10, 2};
    
    cout<<"The given line segments intersect: "<<intersects(p1,q1,p2,q2)<<"\n";
    
    p1 = {10, 0}, q1 = {0, 10}; 
    p2 = {0, 0}, q2 = {10, 10}; 
    cout<<"The given line segments intersect: "<<intersects(p1,q1,p2,q2)<<"\n";
  
    p1 = {-5, -5}, q1 = {0, 0}; 
    p2 = {1, 1}, q2 = {10, 10}; 
    cout<<"The given line segments intersect: "<<intersects(p1,q1,p2,q2)<<"\n";

    return 0;
}