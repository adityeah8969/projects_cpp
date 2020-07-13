#include<bits/stdc++.h>
using namespace std;

class job{
    public:
        int start;
        int end;
        int profit;  
};

int last_job_profit(job arr[], int index){

    int low=0;
    int high = index-1;

    int mid;

    while(low<=high){

        mid = low + (high-low)/2;
        
        if(arr[mid].end<=arr[index].start){
            if(arr[mid+1].end<=arr[index].start){
                low = mid+1;
            }
            else{
                return arr[mid].profit;
            }

        }
        else{
            high = mid-1;
        }
    }

    return -1;
}

bool cmp(job a, job b){return a.end<b.end;}

int maximum_profit_weighted_job_scheduling(job arr[], int n){
    
    sort(arr, arr+n, cmp);

    int dp[n+5];
    for(int i=0;i<=n;i++){dp[i]=0;}

    dp[0] = arr[0].profit;

    int incl;
    int excl;

    for(int i=1;i<n;i++){

        incl = 0;
        excl = 0;

        incl+=arr[i].profit;
        int temp = last_job_profit(arr, i);
        if(temp!=-1){incl+=temp;}
        
        excl = dp[i-1];
        
        dp[i] = max(incl, excl);
    }

    int maxi = 0;

    for(int i=0;i<n;i++){
        maxi = max(dp[i], maxi);
    }
    return maxi;
}

int main(){
    
    job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maximum_profit_weighted_job_scheduling(arr, n);
    return 0;
}