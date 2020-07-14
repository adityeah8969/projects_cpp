#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int get_median_util2(int low, int high, int arr[]){
    int len = (high-low+1);
    int median;
    if(len%2==1){median =  arr[low + (len-1)/2];}
    if(len%2==0){median =  (arr[low+len/2] + arr[low + len/2 -1])/2;}
    return median;
}

int get_median_util1(vector<int> vec){
    int len = vec.size();
    int arr[len+5];
    for(int i=0;i<len;i++){arr[i] = vec[i];}
    sort(arr, arr+len);
    return get_median_util2(0, len-1, arr);
}

int get_median(int arr1[], int arr2[], int l1, int r1, int l2, int r2){

    int len1 = r1-l1+1;
    int len2 = r2-l2+1;

    // use brute force for smaller lengths
    if(len1<=2 && len2<=2){
        vector<int> temp;
        for(int i=l1;i<=r1;i++){temp.push_back(arr1[i]);}
        for(int i=l2;i<=r2;i++){temp.push_back(arr2[i]);}
        return get_median_util1(temp);
    }

    int med1 = get_median_util2(l1, r1, arr1);
    int med2 = get_median_util2(l2, r2, arr2);

    if(med1<med2){
        l1 = l1 + (r1-l1)/2;    //  excluding left half of arr1
        r2 = l2 + (r2-l2)/2;    //  excluding right half of arr2
        return get_median(arr1, arr2, l1, r1, l2, r2);
    }
    else
    if(med1 > med2){
        r1 = l1 + (r1-l1)/2;    //  excluding right half of arr1
        l2 = l2 + (r2-l2)/2;    //  excluding left half of arr2
        return get_median(arr1, arr2, l1, r1, l2, r2);
    }
    else
    {return med1;}

}

int main(){

    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {11, 12, 13, 14, 15, 16, 17, 18, 19 };

    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    cout<<get_median(arr1, arr2, 0, n1-1, 0, n2-1)<<"\n";
    
    return 0;
}