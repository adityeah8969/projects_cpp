#include<bits/stdc++.h>
using namespace std;

int stirling_bell_number(int n, int k){
    int s[n+5][k+5];
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
            s[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            if(i==j || j==1){s[i][j]=1;continue;}   // exactly one way to put i elements into i sets, exactly one way to put i elemets into 1 set
            
            s[i][j] = j*(s[i-1][j]) + s[i-1][j-1];  // if there are already j partitions done then there are j ways to put
        }                                           // the ith element into one of the sets (represented by j*(s[i-1][j])). 
    }                                               // Otherwise if there are j-1 sets available, pick a new set for ith 
                                                    // element (represented by s[i-1][j-1]). 
                                                    
    return s[n][k];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<stirling_bell_number(5,2);
    return 0;
}