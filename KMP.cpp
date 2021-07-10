#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define M 200005

int lps[M]; // this array denotes the LENGTH of proper(can't include first element) longest suffix of the substring
            // which is also a proper prefix(can't include last element).

            // e.g 
            
            // a a a a a 
            // 0 1 2 3 4 

            // a b c d e a b c d 
            // 0 0 0 0 0 1 2 3 4 

// For every mismatch between pattern and text we dont need to start over again. If there is a mismatch between 
// text[i] & pattern[j] then we need to fix i and left shift j = lps[j-1]. This is done because 
// pattern[0, 'lps[j-1]'] initial substring will anyways match text[i - lps[j-1], i-1] substring.

// same concept is getting used while preprocessing lps array.


// IMPORTANT NOTE:
// let j be the pointer for pattern traversal
// j = lps[j-1] not only allows us to skip the prefix which would have anyways got matched but also makes the pointer (j)
// point to the index one more than the last index of matched prefix.

// i.e

// 0 1 2 3 4 5 6 7 8
// a b c d e a b c d 
// 0 0 0 0 0 1 2 3 4 

// if mismatch happens at second b (index 6) then lps[6-1] or lps[5] (value lps[5] = 1) not only allows us to skip
// 1 character from the beginning but also makes j(pointer for pattern traversal) point to 1 that is next character
// after the prefix match is over (in this example 'b' with index 1). So from this point onwards comparison starts
// from index (j = 1).


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
            j = lps[j-1];                                       // here j-1 == m-1 i.e last index of the pattern
            continue;
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
    lps[0] = 0;                     // 0 in RHS is the index
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

// Time Complexity: outer loop is O(N). Inner loop makes the the pointer 'j' decrease at times. Important observation here is that the decrement can happen only
// as many times as the number of increments (matches) before the mismatch. i.e,
// Text:    aaaabaabab
// Pattern: aaaaa
// with 0 based indexing in mind, the first mismatch happens when the inner pointer j=4 (last 'a' of the pattern). Now the decrement will also happen 4 times
// in this case. Next decrement process will happen when i = 7 (second 'b'). In here, since the increment happened twice, therefore the decrement also happened twice.
// So basically to have n negative steps, you need n positive steps & n positive steps means you are done traversing through the whole text.
// So worst time complexity is n + n = 2n which is O(n). The time complexity of building proper prefix suffix table is O(m). 
// Overall time complexity O(m+n).
