#include<bits/stdc++.h>
using namespace std;

#define ll long long int


int count_palindromic_substring(string str){

    int n = str.length();
    bool dp1[n+5][n+5];
    int dp2[n+5][n+5];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp2[i][j]=0;
            dp1[i][j]=false;
        }
    }

    for(int i=0;i<n;i++){
        dp1[i][i]=true;
        dp2[i][i]=1;
        if(i+1<n){
            if(str[i]==str[i+1]){
                dp1[i][i+1]=true;
                dp2[i][i+1]=3;
            }
            else{
                dp2[i][i+1]=2;
            }
        }
    }

    for(int l=2;l<n;l++){
        for(int i=0;i+l<n;i++){
            int j = i+l;
            if(str[i]==str[j] && dp1[i+1][j-1]){dp1[i][j]=true;}
            dp2[i][j] = dp2[i+1][j]+dp2[i][j-1]-dp2[i+1][j-1];
            if(dp1[i][j]){dp2[i][j]++;} // 1 more for str[i]==str[j] or dp1[i][j]==true
        }
    }

    return dp2[0][n-1]; 
}

int main(){
    string str = "abaab"; 
    cout << "Total palindromic subsequence are : "
         << count_palindromic_substring(str) <<"\n"; 
    return 0; 
}
