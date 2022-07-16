#include <iostream>
using namespace std;
// naive approach: theta(n^2)
//leftmost and rightmost bars can never store water
//we can only store water in middle bars
// so now we traverse through all the middle bars from i=1 to n-1
// now prob is how much water we can store in middle bars
//foe every ith bar we will check left most max height bar(lmax) and right most max height bar(rmax) , then amount of water stored for that bar would be: min(lmax, rmax)-arr[i](height of the present bar)
/*
int getWater(int arr[], int n){
    int res=0;
    for(int i=1; i<n-1; i++){ //middle bars only
        int lmax=arr[i];
        for(int j=0; j<i; j++){
            lmax=max(lmax, arr[j]);
        }
        int rmax=arr[i];
        for(int j=i+1; j<n; j++){
            rmax=max(rmax, arr[j]);
        }
        res=res+(min(lmax, rmax)-arr[i]);
    }
    return res;
}
int main(){
    int arr[]={3, 0, 1, 2, 5}, n=5;
    cout<<getWater(arr, n);
}
*/
//efficient approach : theta(n)
//idea:
//pre-compute left max and right max, rather than computing it for every index
//how to compute:
//initialize lmax[0] as arr[0], now we check for every element, if i-th element is greater than the previous left max and e upgrade left max accordingly

int getWater(int arr[], int n){
    int res=0;
    int lmax[n], rmax[n];
    lmax[0]=arr[0];
    for(int i=1; i<n; i++){
        lmax[i]=max(arr[i], lmax[i-1]);
    }
    rmax[n-1]=arr[n-1];
    for(int i=n-2; i>=0; i--){
        rmax[i]=max(arr[i], rmax[i+1]);
    }
    for(int i=1; i<n-1; i++){
        res=res+(min(lmax[i], rmax[i])-arr[i]);
    }
    return res;
}
int main(){
    int arr[]={3, 0, 1, 2, 5}, n=5;
    cout<<getWater(arr, n);
}