#include <bits/stdc++.h>
using namespace std;

int arr[15]={15,2,31,4,78,9,11,3,20,111,45,67,25,98,32};
const int N=15;
int M[N][(int)log2(N)+2];

#define ll long long int

// Time Complexity O(NlogN) ->preprocessing  + O(1) -> per query
// M[i][j] stores the INDEX with minimum arr[i] value where index E [i,i+(1<<j)-1]
// e.g M[2][3] stores the index with minimum arr[i] value where index E [2,9] i.e chunk of pow(2,j) indices inclusive of index 2.

void preProcess(){
    
    for(int i=0;i<N;i++){M[i][0]=i;}
    
    for(int j=1;(1<<j)<=N;j++){
        for(int i=0;(i+(1<<j)-1)<N;i++){
            if(arr[M[i][j-1]]<arr[M[i+(1<<(j-1))][j-1]]){M[i][j]=M[i][j-1];}  // e.g arr[M[2][4]]= min(arr[M[2][3]],ar[M[10][3]])
            else{M[i][j]=M[i+(1<<(j-1))][j-1];}                               //          [2,17]             [2,9]      [10,17]
        }
    }
    return;
}

ll query(int i,int j){
    int k=log2(j-i+1);                                                      // consider i=3 ,j=9 then k=2
    ll ans=min(arr[M[i][k]],arr[M[j-(1<<k)+1][k]]);                         // ans =min(arr[M[3][2]],arr[M[6][2]])
    return ans;                                                             //                [3,6]        [6,9]      (note index 6 is common here)
}                                                                           // set of common indices are supposed tooccur in case (j-i+1) is not a power of 2.
                                                                            // if its a power of 2 then both the left and right arguments of 'min(left,right)'  will be the same.

int main() {
    preProcess();
    cout<<query(1,5)<<"\n";
    cout<<query(2,9)<<"\n";
    cout<<query(10,14)<<"\n";
    cout<<query(3,11)<<"\n";
    return 0;
}



