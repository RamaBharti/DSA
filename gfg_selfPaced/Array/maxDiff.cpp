#include <iostream>
using namespace std;
//Maximum Difference problem is to find the maximum of arr[j] - arr[i] where "j>i".
//naive approach: theta(n^2)
//intialize res as difference between first pair
//now we consider every pair
/*
int maxDifference(int arr[], int n){
    int res=arr[1]-arr[0];
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            res=max(res, arr[j]-arr[i]);
        }
    }
    return res;
}
int main(){
    int arr[]={2, 3, 10, 6, 4, 8, 1}, n=7;
    cout<<maxDifference(arr, n);

}
*/
//efficient solution: theta(n)
//idea:
//consider every element as array j, the right element
//we also keep track of mimimun element so far
//so for every element, arr[j] will give max diff when we consider the min element left of it
//so traverse the array from left to right, keep the track of min element that we have got so far and for every element we subtract min element from it and update the min element whenever we find the smaller element
int maxDifference(int arr[], int n){
    int res=arr[1]-arr[0];
    int minVal=arr[0];
    for(int j=1; j<n; j++){
        res=max(res, arr[j]-minVal);
        minVal=min(minVal, arr[j]);
    }
    return res;
}
int main(){
    int arr[]={2, 3, 10, 6, 4, 8, 1}, n=7;
    cout<<maxDifference(arr, n);

}