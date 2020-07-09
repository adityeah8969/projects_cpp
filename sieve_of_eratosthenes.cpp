#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define M 1000*1000 + 7

bool prime[M];
ll spf[M];

void sieve_of_eratosthenes(){

    for(int i=0;i<M;i++){prime[i]=true;spf[i]=i;}

    for(int i=2;i*i<M;i++){
        if(prime[i]){
            for(int j=2*i;j<M;j+=i){
                prime[j]=false;
                spf[j]=min(spf[j],i);
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve_of_eratosthenes();
    return 0;
}