#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void merge(int arr[],int low,int mid,int high){

    int i,j,k;
    int n1 = mid-low+1;                                         // calc n1, n2
    int n2 = high-mid;

    int left[n1],right[n2];

    int x;
    for(x=0;x<n1;x++){
        left[x] = arr[x+low];
    }

    for(x=0;x<n2;x++){
        right[x] = arr[x+mid+1];
    }

    i=0;
    j=0;
    k=low;                                                     // PAY ATTENTION , K=low

    while(i<n1 && j<n2){
        if(left[i]<=right[j]){
            arr[k]=left[i];                                    // same arr[] getting used
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
            k++;
    }

    while(i<n1){
        arr[k]=left[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k]=right[j];
        j++;
        k++;
    }

    return;
}


void merge_sort(int arr[], int low, int high){

    if(low==high){return;}

    int mid = low+(high-low)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
    return;
}

void display_sorted(int arr[], int len){
    for(int i=0;i<len;i++){cout<<arr[i]<<" ";}
    return ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {5,4,8,6,3,1,7,8,5,2,4,98,56,21};
    int n = sizeof (arr)/ sizeof(arr[0]) ;

    merge_sort(arr,0,n-1);
    display_sorted(arr,n);
    return 0;
}