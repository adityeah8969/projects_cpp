#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int do_partition(int arr[], int low, int high){
    int i = low;
    for(int j=low;j<high;j++){
        if(arr[j] <= arr[high]){
            swap(arr[j], arr[i]);
            i++;                                                   //*
        }
    }
    swap(arr[i],arr[high]);                                        //*
    return i;
}

int random_partition(int arr[], int low, int high){
    int n = high-low+1;
    srand(time(0));
    int p = low + rand()%n;
    swap(arr[high], arr[p]);                                        //  *
    return do_partition(arr, low, high);                            //  *
}

int kth_smallest(int arr[], int low, int high, int k){
    if(k>=low && k<=high){                                          //*
        int pos = random_partition(arr, low, high);
        if(pos == k){return arr[pos];}
        if(pos > k){return kth_smallest(arr, low, pos-1, k);}
        return kth_smallest(arr, pos+1, high, k);
    }
    cout<<k<<" not in range";
    return INT_MAX;
}

void quicksort(int arr[], int low, int high){
    if(low<high){
        int p = random_partition(arr, low, high);           // random_partition internally calls do_partition 
        quicksort(arr, low, p-1);                           // which actually returns the partition index
        quicksort(arr, p+1, high);
    }
    return;
}

int main(){

    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=4;
    cout<<"kth smallest number: "<<kth_smallest(arr, 0, n-1, k-1)<<"\n";

    int arr1[] = {12, 3, 5, 7, 4, 19, 26};
    quicksort(arr1,0,n-1);

    cout<<"sorted arr1: ";
    for(int i=0;i<n;i++){cout<<arr1[i]<<" ";}

    return 0;
}