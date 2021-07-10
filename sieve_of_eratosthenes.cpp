#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define M 1000*1000 + 7

bool prime[M];
int spf[M];

void sieve_of_eratosthenes(){
    for(int i=0;i<M;i++){prime[i]=true;spf[i]=i;}
    for(int i=2;i*i<M;i++){                         //* i*i<M  cause the smallest prime factor of a composite should always be lesser than sqrt(n)
        if(prime[i]){
            for(int j=2*i;j<M;j+=i){                //* j<M
                prime[j]=false;
                spf[j]=min(spf[j],i);
            }
        }
    }
    return;
}

void show_primes(int cnt){
    cout<<"showing first "<<cnt<<" prime numbers\n";
    for(int i=1;i<100;i++){
        if(prime[i]){cout<<i<<" ";}
    }
    cout<<"\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve_of_eratosthenes();
    int cnt=100;
    show_primes(cnt);
    return 0;
}
// Time complexity: O(n*log(log(n)))
// (n/2) + (n/3) + (n/5) + (n/7) ... = n(1/2 + 1/3 + 1/5 + 1/7 ...) = n*(log(log(n)))