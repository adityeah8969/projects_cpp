#include<bits/stdc++.h>
using namespace std;

#define ll long long int

// works only for sorted arrays
int longest_length_AP(int arr[], int n){

    if(n<2){return n;}

    int dp[n][n];               // dp[i][j] : length of longest AP subsequence with i as first and j as second element.
    int llap = 2;

    for(int i=0;i<n-1;i++){dp[i][n-1]=2;}   // if n-1 is the 2nd element there can't be any more elements in the AP
                                            // note 0 based indexing has been used in arr[]

    // j will be the middle index around which the expansion will take place.
    // we will set value corresponding to changes in i & j (not k).
    for(int j=n-2;j>=0;j--){

        int i=j-1;
        int k=j+1;

        while(i>=0 && k<=n-1){
            if(arr[i] + arr[k] < 2*arr[j]){k++;}    // no change in dp[i][j] as only k got changed
            else
            if(arr[i] + arr[k] > 2*arr[j]){
                dp[i][j]=2;
                i--;
            }
            else{
                dp[i][j] = 1 + dp[j][k];            // dp[j][k] already filled cz we are moving from right to left
                llap = max(llap, dp[i][j]);
                i--;k++;
            }
        }

        while(i>=0){                        // in case k goes past n-1, we need to set all the i's for 
            dp[i][j] = 2;                   // that particular j.
            i--;
        }

    }
    return llap;
}

int main(){

    int sorted_arr[] = {1, 7, 10, 13, 14, 19};
    int n = sizeof(sorted_arr)/sizeof(sorted_arr[0]);
    cout<<"length of longest AP: "<<longest_length_AP(sorted_arr, n);

    return 0;
}
