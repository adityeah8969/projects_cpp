#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define M 200005

int lps[M]; // this array denotes the longest suffix of the substring pattern (0,i) which is also a prefix.

// For every mismatch between pattern and text we dont need to start over again. If there is a mismatch between 
// text[i] & pattern[j] then we need to fix i and left shift j = lps[j-1]. This is done because 
// pattern[0, 'lps[j-1]'] initial substring will anyways match text[i - lps[j-1], i-1] substring.

// same concept is getting used while preprocessing lps array.

void KMP_search(string text,string pattern){ 

    int n = text.length();
    int m = pattern.length();

    int i=0;
    int j=0;

    while(i<n){

        if(text[i] == pattern[j]){
            i++;
            j++;
        }

        if(j==m){
            cout<<"pattern found at position: "<<i-m<<"\n";
            j = lps[j-1];
        }

        if(i<n && pattern[j]!=text[i]){
            if(j!=0){j = lps[j-1];}
            else{i++;}
        }
    }
    return;
}

void compute_lps_array(string pattern){

    int n = pattern.length();
    lps[0] = 0;
    int len = 0;
    int i=1;

    while(i<n){

        if(pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len!=0){len = lps[len-1];}
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return;
}

void init(){
    for(int i=0;i<M;i++){lps[i] = M;}
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string text = "abcdhfifabcdnsfdkpoabcaaababc";
    string pattern = "abc";
    
    init();

    compute_lps_array(pattern);
    KMP_search(text,pattern);

    return 0;
}