#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll gcd(ll a, ll b) 
{ 
    if (b == 0){return a; }
    return gcd(b, a % b);  
} 

// a.x + b.y = gcd                  ... eqn 1
// (b%a).x1 + a.y1 = gcd  
// (b - (⌊b/a⌋).a).x1 + a.y1  = gcd
// b.x1 + a.(y1 - (⌊b/a⌋).x1) = gcd ... eqn2
// x = y1 - ⌊b/a⌋ * x1
// y = x1

ll gcd_extended(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd_extended(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll mod_inverse(ll a, ll m){
    ll x,y;
    ll g = gcd_extended(a,m,x,y);
    ll res= -1;
    if(g!=1LL){cout<<"modular inverse does not exist\n";}
    else{res = (x%m + m)%m;}
    return res;
}

int main() {
    
    cout<<gcd(7, 876543)<<"\n";
    cout<<gcd(54, 888)<<"\n";
    cout<<gcd(90, 6)<<"\n";
    cout<<gcd(125348, 18)<<"\n";

    cout<<"\n gcd_extended: ";
    ll x,y;
    cout<<gcd_extended(54, 888, x, y)<<"\n";
    cout<<"x: "<<x<<"\n";
    cout<<"y: "<<y<<"\n";


    ll a=3;
    ll m=11;
    cout<<"modular inverse of "<<a<<" modulo "<<m<<" is: "<<mod_inverse(a,m);

    return 0;
}