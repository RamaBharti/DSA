//Frequencies of elements in A Sorted Array
#include <iostream>
using namespace std;
//i/p: {10, 10, 10, 25, 30, 30}
/*o/p: 10 3
       25 1
       30 2
*/       
//start with the 2nd element and check if its same as the prev element and increment the freq accordingly
//as soon as we find that the curr element is not same as the prev element that means the freq of prev element is known to us as the array is sorted
void printFreq(int arr[], int n){
    int freq=1, i=1;
    while(i<n){
        while(i<n && arr[i]==arr[i-1]){
            freq++;
            i++;
        }
        cout<<arr[i-1]<<" "<<freq<<endl;
        i++;
        freq=1;
    }
    if(n==1|| arr[n-1]!=arr[n-2]){
        cout<<arr[n-1]<<" "<<"1"<<endl;
    }
}
int main(){
    int arr[]={40, 50, 50, 50, 70, 90, 90}, n=7;
    printFreq(arr, n);
}