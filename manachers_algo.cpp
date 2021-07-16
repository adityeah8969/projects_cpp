#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define M 200005

int t[M];


// video explanation
// https://www.youtube.com/watch?v=V-sEwsca1ak

// Linear time Manacher's algorithm to find longest palindromic substring.

// Expand across an index till there is a character mismatch, let this be called current palindrome centered at index i.
// We cannot linearly go about expanding across every other element, cause that will make the algorithm have O(n*n) complexity.
// Let's call the next candidate across which the expansion is going to happen 'C'. Let following be the, current state where 
// the expansion has already happened across index 3 ('x'), and we hit a mismatch.
//
// str = a b a x a b a x a b b 
// t[] = 1 3 1 7 
// ind = 0 1 2 3 4 5 6 7 8 9 10
//
// Now the next candidate would be one among 'a', 'b', 'a' with indices 4, 5, 6 respectively.
// 
// t[4] = t[2] = 1  copying the mirror index about the current palindrome indexed at 3. If we pick C = t[4], this still does not
// go past the right of the current plaindrome which we have found across index 3.
//
// t[5] = t[1] = 3 although we have copied t[5] to be 3, but if we pick C = t[5], this is actually hitting the right edge of the
// current palindrome centered at index 3. so t[5] >= 3.
// 
// t[6] = [0] = 1, t[6] >= 1 by the same logic above.
// But t[5] > t[6], so t[5] will be our next C.
//
// Following are the cases to consider while picking up next C in general,

// Case 1 : Right side palindrome (across expected C) is totally contained under current palindrome. 
//          In this case do not consider this as center. Because anyways it cannot extend beyond the right boundary of current palindrome.

// Case 2 : Current palindrome is proper suffix of input. Terminate the loop in this case. 
//          No better palindrom will be found on right. All the palindromes on the right would definitely be of smaller lengths.

// Case 3 : Right side palindrome (across expected C) is proper suffix and its corresponding left side palindrome is proper prefix of 
//          current palindrome. Make largest such point as next center. There is a possibility that this palindrome may get extended.

// Case 4 : Right side palindrome ((across expected C) is proper suffix but its left corresponding palindrome is be beyond current palindrome. 
//          Do not consider this as center because it will not extend at all.
//          EXtension will not happen because the current palindrome itself would have got extended had there been
//          any other character match.

// To handle even size palindromes replace input string with one containing # between every input character 
// and in start and end. 

// i/p: abcd ---> o/p: #a#b#c#d#
string modify(string str){                  //*
    string res="";
    int len = str.length();
    for(int i=0;i<len;i++){
        res+='#';
        res+=str[i];
    }
    res+='#';
    return res;
}

void manachers_algo(string str){

    string s = modify(str);

    int len = s.length();
    int start = 0;                  //*
    int end = 0;                    //*

    for(int i=0;i<len;){

        // while there is a match expand the palindrome in both directions.
        while( start-1>=0 && end+1<len && s[start-1] == s[end+1]){
            start--;
            end++;
        }

        t[i] = end - start + 1;     
        
        // breaking the loop if right end of current palindrome reaches the end of string.
        if(end == len-1){break;}    //*

        // making sure that we always pick a normal string character(not '#') for initializing new_center.
        // note that 'new_center' may get changed in the later section of code
        int new_center = end + (i%2 ==0 ? 1 : 0);      //*

        // following loop checks for new_center on the right of i.
        for(int j=i+1;j<len;j++){
            // j-i will keep increasing from 1 onwards, so i - (j-i) represents left shift of i by (j-i).
            //[i-(j-i)] represents the index of left mirror of the current palindrome centered at i shifted left by (j-i).
            //if t[i-(j-i)] crosses the leftmost bound of current palindrome centered (i) then we pick '2*(end-j)+1'.
            //2*(end-j)+1 denotes the length of the palindrome at [i-(j-i)] contained within the current palindrome
            //centered at i.
            t[j] = min(t[i-(j-i)],2*(end-j)+1);         //*

            //new_center will only be picked in case the palindrome situated at [i-(j-i)] index (left mirror index)
            // is a proper prefix of the current palindrome centered at i. 
            if(j+t[i-(j-i)]/2 == end){                  //*
                new_center = j;
                break;                                  //*
            }
        }

        i = new_center;
        start = i - t[i]/2;
        end = i + t[i]/2;
    }

    int maxi = 1;
    for(int i=0;i<len;i++){maxi = max(maxi,t[i]);}
    cout<<"The maximum length palindromic substring is "<<maxi/2<<"\n";         //* maxi/2

    return;
}

int main(){
    string str = "abaab";
    // string str = "abaxabaxabybaxabyb";
    manachers_algo(str);
    
    return 0;
}
