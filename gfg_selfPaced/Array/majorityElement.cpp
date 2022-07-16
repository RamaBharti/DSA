//Majority element is an element that appears more than n/2 times in an array of size n, if it exists.
//return index of the element
//eg- {8,3,4,8,8}: o/p- 0 or 3 or 4
//return -1 if no such element exist
#include <iostream>
using namespace std;

//naive approach
//idea:
//traverse through all the elements
//for every element count the number of times it appears in the array
//if count>n/2, return index of this element 
/*
int findMajority(int arr[], int n){
    for(int i=0; i<n; i++){
        int count=1;
        for(int j=i+1; j<n; j++){
            if(arr[i]==arr[j])
                count++;
        }
        if(count>n/2){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[]={8, 7, 6, 8, 6, 6, 6, 6}, n=8;
    cout<<findMajority(arr, n);
}
*/
//efficient sol: O(n) time, O(1) aux space : Moore's voting algorithm
//works in two phases:
//1.finds out a candidate and first phase guarantees that if there is a majority element in the array then this candidate is going to be the majority element
//2. 2nd phase checks whether the candidate fount out by the first phase is actually a majority or not
//the need of 2nd phase is only when there is no any majority element in the array.
//this algorithm may not always give the 1st occurence of the majority element

int findMajority(int arr[], int n){
 //1st phase, find a candidate
 int res=0, count=1;
 for(int i=0; i<n; i++){
    if(arr[res]==arr[i]){
        count++;
    }else{
        count--;
    }
    if(count==0){
        res=i;
        count=1;
    }
 }
 //2nd phase, check if the candidate is actually a majority
 count=0;
 for(int i=0; i<n; i++){
    if(arr[res]==arr[i]){
        count++;
    }
 }
 if(count<=n/2){
    res=-1;
 }
 return res;
}
int main(){
    int arr[]={8, 7, 6, 8, 6, 6, 6, 6}, n=8;
    cout<<findMajority(arr, n);
}

