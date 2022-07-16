//Find count of maximum consecutive 1s in a binary array.
#include <iostream>
using namespace std;

//naive approach: O(n^2), O(1) aux space

//idea:
//traverse through every element, for every element we count how many consecutive 1s are there, beginning with this element, 
//intialize count=0, then traverse through every element, if arr[j]==1, upgrade the count otherwise break the loop
/*
int maxConsecutiveOnes(int arr[], int n){
    int res=0;
    for(int i=0; i<n; i++){
        int curr=0;
        for(int j=i; j<n; j++){
            if(arr[j]==1)
                curr++;
            else
                break;
        }
        res=max(res, curr);
    }
    return res;
}
int main(){
    int arr[]={0, 1, 1, 1, 0, 1, 1}, n=7;
    cout<<maxConsecutiveOnes(arr, n);
}
*/
//efficient approach: theta(n) time, O(1) aux space
//traverse the array from left to right
//whenever we see a zero, we reach at the curr count and whenever we see a 1 we increment the current count and compare with the result

int maxConsecutiveOnes(int arr[], int n){
    int res=0, curr=0;
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            curr=0;
        }else{
            curr++;
            res=max(res, curr);
        }
    }
    return res;
}
int main(){
    int arr[]={0, 1, 1, 1, 0, 1, 1}, n=7;
    cout<<maxConsecutiveOnes(arr, n); 
}