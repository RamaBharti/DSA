//An element is called the leader of an array if there is no element greater than it on the right side.
//i/p: {7, 10, 4, 3, 6, 5, 2} 
//o/p: 10, 6, 5, 2

//i/p: {10, 20, 30}
//o/p: 30

//i/p: {30, 20, 10}
//o/p: 30 20 10
//so a leader> all the elements on the right side (>= is not applicable)
//LAST ELEMENT IS ALWAYS A LEADER

#include <iostream>
using namespace std;

//naive approach: O(n^2) :print sol from left to right

//traverse through every element and for every element traverse on right side of it
//if we find an element>= , break the loop
//this is not a leader and if we never broke the loop then thats a leader
/*
void leaders(int arr[], int n){
    for(int i=0; i<n; i++){
        bool flag=false;
        for(int j=i+1; j<n; j++){
           if(arr[j]>=arr[i]){
            flag=true;
            break;
           }
        }
        if(flag==false){
            cout<<arr[i]<<" ";
        }
    }
}
int main(){
    int arr[] = {7, 10, 4, 10, 6, 5, 2}, n = 7;
    leaders(arr, n);
}
*/

//efficient approach: theta(n), print sol from right to left

//traverse from the right side
//since the last element is always a leader so we print it as curr leader
//then compare the next element with the curr leader
//if the next element>curr leader
//then this is also a leader element

void leaders(int arr[], int n){
    int curr_ldr=arr[n-1];
    cout<<curr_ldr<<" ";
    for(int i=n-2; i>=0; i--){
        if(arr[i]>curr_ldr){
            curr_ldr=arr[i];
            cout<<curr_ldr<<" ";
        }
    }
}
int main() {
	int arr[] = {7, 10, 4, 10, 6, 5, 2}, n = 7;
    leaders(arr, n);  
}