#include <iostream>
using namespace std;
//naive approach: O(n^2)
//idea:
//we traverse the array from the left to right
//for every element we will check that there should not be any smaller element to the right of it
/*
bool isSorted(int arr[], int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[i]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    int arr[]={7, 20, 30, 10};
    cout<<isSorted(arr, 4)?"true":"false";
}
*/

//efficient approach: linear time
//idea:
//we traverse from left to right and if we find any out of order elements, we immediately return false, and if we reached at elements ai that means elements from a1 to a(i-1) are already sorted otherwise we would have immediately retured false and a(i-1) has largest value till left of ai
bool isSorted(int arr[], int n){
    for(int i=0; i<n; i++){
        if(arr[i]<arr[i-1])
            return false;
    }
    return true;
}
int main(){
    int arr[]={7, 20, 30, 10};
    cout<<isSorted(arr, 4)?"true":"false";
}

