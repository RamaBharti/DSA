#include <iostream>
using namespace std;
//naive approach: theta n + O(n) i.e. theta n or O(n), requires theta n auxiliary space as we need temp array of size n
//we create a temp array of same size and copy only the distinct elements to this temp array and finally we copy to the original array
//1st element is always going to be a part of our output
//so we copy the 1st element to our temp array
//initialize the size of temp array as 1: res=1 as we have copied one element
//now for the next every element we check if it is the same as the last copied element to the temp array
//if it is not same as the last copied element, we increment the result and copy this element to the next location of the temp array
// and finally copy the temp array to the original one
/*
int remDups(int arr[], int n){
    int temp[n];
    temp[0]=arr[0];
    int res=1; //size of temp array
    for(int i=1; i<n; i++){    //theta n
        if(temp[res-1]!=arr[i]){
            temp[res]=arr[i];
            res++;
        }
    }
    for(int i=0; i<n; i++){    //O(n)
        arr[i]=temp[i];
    }
    return res;
}

int main(){
    int arr[]={10, 20, 20, 30, 30, 30}, n=6;
    cout<<"Before removal"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    n=remDups(arr, n);
    cout<<"After removal"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
*/

//efficient approach: does not require any extra space, time comp same
//here we do not use any extra array rather we use the same array: saves extra space and extra work
//here too, initialise res=1
//start from the 2nd element and then we compare every element with the last element that we include in our result

int remDups(int arr[], int n){
    int res=1;
    for(int i=1; i<n; i++){
        if(arr[i]!=arr[res-1]){
            arr[res]=arr[i];
            res++;
        }
    }
    return res;
}

int main(){
    int arr[]={10, 20, 20, 30, 30, 30}, n=6;
    cout<<"Before removal"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    n=remDups(arr, n);
    cout<<"After removal"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}