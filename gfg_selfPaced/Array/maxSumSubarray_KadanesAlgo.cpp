//Explanation of the Kadane's algorithm.
#include <iostream>
using namespace std;
//subarray-contiguous elements picked from the array
//subarrays of {1, 2, 3} - arr{1}, {2}, {3}, {1, 2}, {2, 3}, {1, 2, 3}
//when all elements are +ve: output is sum of all the elements

//naive approach: O(n^2) time
//traverse through all the subarrays and for every subarray we find the sum of it
//and if current sum is greater than max sum we found so far, we update the max sum
/*                                          //for i=0
int maxSum(int arr[], int n){             //curr=0                                                              
    int res=arr[0];                       //curr=1
    for(int i=0; i<n; i++){               //curr=1-2=-1
        int curr=0;                       //curr=-1+3=2  res=2
        for(int j=i; j<n; j++){           //curr=2-1=1
            curr=curr+arr[i];             //curr=1+2=3   res=3
            res=max(res, curr);           //for i=1
        }                                 //curr=-2
    }                                     //curr=-2+3=1
    return res;                           //curr=1-1=0
}                                         //curr=0+2=2 and so on
int main(){                                 
    int arr[]={1, -2, 3, -1, 2}, n=5;
    cout<<maxSum(arr, n);
}*/

//efficient approach: O(n) time, O(1) extra space
//idea:
//either extend the previous subarray or add the new subarray
//if we have to find the max ending with the current element we will have to go through the previous element
//maxEnding+arr[i]: extend the previous subarray
//arr[i]- start a new subarray

int maxSum(int arr[], int n){
    int res= arr[0];
    int maxEnding=arr[0];
    for(int i=1; i<n; i++){
        maxEnding=max(maxEnding+arr[i], arr[i]);
        res=max(res, maxEnding);
    }
    return res;
}
int main(){
    int arr[]={-3, 8, -2, 4, -5, 6}, n=6;
    cout<<maxSum(arr, n);
}

