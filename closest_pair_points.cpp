#include<bits/stdc++.h>
using namespace std;

#define ll long long int

class point{
    public:
        double x;
        double y;
};

point[] p = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};

bool cmp_x(point a, point b){
    return a.x < b.x;
}

bool cmp_y(point a, point b){
    return a.y < b.y;
}

double dist(point a, point b){
    double temp = 0.0;
    temp+=(a.x - b.x)*(a.x - b.x);
    temp+=(a.y - b.y)*(a.y - b.y);
    return sqrt(temp);
}

double brute_force(int low, int high){

    double mini = INT64_MAX;

    for(int i=low;i<=high;i++){
        for(int j=low+1;j<=high;j++){
            mini = min(mini, dist(p[i], p[j])); 
        }
    }
}

double closest_pair_of_points_on_strip(vector<double> strip, double d){

    sort(strip.begin(), strip.end(), cmp_y);
    int len = strip.length();
    double mini = d;

    for(int i=0;i<len;i++){
        for(int j=i+1;j<len && abs(p[i].y-p[j].y)<d;j++){
            mini = min(d, dist(p[i], p[j]));
        }
    }
    return mini;
}

double closest_pair_of_points(int low, int high){

    if(high-low+1 <= 3){
        return brute_force(low, high);
    }

    int mid = low+(high-low)/2;
    point mid_point = p[mid];
    double dl = closest_pair_of_points(low, mid);
    double dr = closest_pair_of_points(mid+1, high);
    double d = min(dl, dr);

    vector<double> strip;7
    for(int i=low;i<=high;i++){
        if(abs(mid_point.x - p[i].x)<d){
            strip.push_back(p[i]);
        }
    }

    double d_strip = closest_pair_of_points_on_strip(strip, d);
    return min(d_strip, d);
}

int main(){

    int n =sizeof(p)/sizeof(p[0]);
    sort(p, p+n, cmp_x);
    cout<<closest_pair_of_points(0, n-1);

    return 0;
}