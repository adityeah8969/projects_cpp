#include<bits/stdc++.h>
using namespace std;

// steps:

// Find indices x, y in nums1, nums2 respctively with the following constraints,

// i> all elements on the left side of index 'x' in nums1 (0 <= indices < x) are  <= 
//    all elements on the right side of index 'y' in nums2 (y <= indices <= nums2.length()-1)

// ii> all elements on the left side of index 'y' in nums2 (0 <= indices < y) are  <= 
//     all elements on the right side of index 'x' in nums1 (x <= indices <= nums1.length()-1)


// After finding such indices, we have essentially divided vectors in two halves, and now the
// elements in left side of any vector is smaller than elements in right side of any vector.

// Because the above constraints hold true, we can easily find the median based on 4 elements,
// left_x = nums1[x-1]
// right_x = nums1[x]
// left_y = nums2[y-1]
// right_y = nums2[y]

// for odd length array median -> max(left_x, left_y)
// for even length array median -> (max(left_x, left_y) + min(right_y, right_x))/2

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    
    int m = nums1.size();
    int n = nums2.size();
    
    if (m>n) {
        return findMedianSortedArrays(nums2, nums1);
    }
    
    bool odd = ((m+n)%2 == 1);
    int total = (m+n);
    
    
    if(m == 0){
        if(odd) {
            return (double) nums2[total/2];
        }
        return (double)((nums2[total/2] + nums2[total/2 - 1])/2.0);
    }
    
    
    int low = 0;
    int high = m;
    
    while(low<=high){
        
        int px = low + (high-low)/2;
        int py = (m+n+1)/2 - px;                    // (m+n+1)/2 not only gives us an estimate of where py could be, but also 
                                                    // makes sure we have larger number of elements in case the combined length is odd.
                                                    // this way the median always lies in the left half, in case we are able to divide 
        int left_x = px==0?INT_MIN:nums1[px-1];     // the vectors perfectly based on the constraints.
        int right_x = px==m?INT_MAX:nums1[px];
        
        int left_y = py==0?INT_MIN:nums2[py-1];
        int right_y = py==n?INT_MAX:nums2[py];
        
        if(left_x<=right_y && left_y<=right_x){
            
            if(odd){
                return (double) max(left_x, left_y);
            }
            
            double res = max(left_x, left_y) + min(right_y, right_x);
            res /= 2.0;
            return res;
        }
        else if(left_x > right_y ){
            high--;
        }
        else{
            low++;
        }
        
    }
    return -1;
}
    
int main(){

    vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> nums2 = {11, 12, 13, 14, 15, 16, 17, 18, 19 };
    cout<<findMedianSortedArrays(nums1, nums2)<<"\n";

    
    
    return 0;
}
