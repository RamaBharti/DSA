//max sum of a circular subarray (also includes normal subarray)
//The task is to find maximum circular sum subarray of a given array. 
//subarrays of {10, 5, -5}: 
//{10}, {5}, {-5}, {10,5}, {5, -5}, {10,5,-5} - these all normal subarrays + {5, -5, 10}, {-5, 10}, {-5, 10, 5} - circular
#include <iostream>
using namespace std;
//naive approach: O(n^2)
/*
int maxCircularSum(int arr[], int n){
    int res=arr[0];
    for(int i=0; i<n; i++){
        int currMax=arr[i];
        int currSum=arr[i];
        for(int j=1; j<n; j++){
            int index=(i+j)%n;
            currSum+=arr[index];
            currMax=max(currMax, currSum);
        }
        res=max(res, currMax);
    }
    return res;
}
int main(){
    int arr[]={5, -2, 3, 4}, n=4;
    cout<<maxCircularSum(arr, n);
}
*/

//efficient approach: O(n)
//idea: find max of following two values
//1.max sum of normal subarray(easy:using kadance algo)
//2.max sum of a circular subarray(how to find this? this part also use kadence algo)

//standard kadance
int normalMaxSum(int arr[], int n){
    int res=arr[0], maxEnding=arr[0];
    for(int i=0; i<n; i++){
        maxEnding=max(arr[i], maxEnding+arr[i]);
        res=max(res, maxEnding);
    }
    return res;
} 

int overallMaxSum(int arr[], int n){
    int maxNormal=normalMaxSum(arr, n); //normal sum
    if(maxNormal<0){
        return maxNormal;
    }
    //circular sum
    int arrSum=0;
    for(int i=0; i<n; i++){
        arrSum+=arr[i];
        arr[i]=-arr[i];
    }
    int maxCircular=arrSum+normalMaxSum(arr, n);

    return max(maxNormal, maxCircular);
}
int main(){
    int arr[]={5, -2, 3, 4}, n=4;
    cout<<overallMaxSum(arr, n);
}