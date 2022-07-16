//three methods to Left Rotate an Array by D places.
//d<=no. of elements in the array(n)
//if d>n then use (d-n) for effective no of rotations

#include <iostream>
#include <cmath>
using namespace std;
//i/p= {1, 2, 3, 4, 5} d=2
//o/p= {3, 4, 5, 1 ,2}
/***********************************************************/
//method1: naive approach
//theta(n*d) time, theta(1) aux space

// simply call the 'left rotate by one' d times
/*
void leftRotateOne(int arr[], int n){
    int temp=arr[0];
    for(int i=0; i<n; i++){
        arr[i-1]=arr[i];
    }
    arr[n-1]=temp;
}
void leftRotateD(int arr[], int n, int d){
    for(int i=0; i<d; i++){
        leftRotateOne(arr, n);
    }
}*/
/***********************************************************/

//method2: better(efficient) approach
// theta(n) time : theta(d+(n-d)+d) : theta(n+d) : theta(n) as d<=n
//aux space array of size d: theta(d)

//idea:
//we first copy the first d elements into a temporary array.
//it is similar to left rotate by one action (there we were copying the 1st element, here we are copying the 1st d element into a temp array)
/*
void leftRotateD(int arr[], int n, int d){
    int temp[d];
    for(int i=0; i<d; i++){
        temp[i]=arr[i]; //copy 1st d elemets into the temp array {1, 2}
    }
    for(int i=d; i<n; i++){
        arr[i-d]=arr[i]; //shifting d position back from index d {3, 4, 5, 4, 5}
    }
    for(int i=0; i<d; i++){
        arr[n-d+i]=temp[i]; //copying {3, 4, 5, 1, 2} 1 is at (n-d), 2 is at (n-d+1)
    }
}*/
/***********************************************************/

//method3: reversal method
//theta(n) time, theta(1) aux space

//idea:
//we will make a reverse fn which is reversing the array between the two indices(low and high) including the two indices
//algo for the reverse fn
//first reverse the first d elements from 0 to d-1
//then reverse the remaining n-d elements from d to n-1
//then finally reverse the whole array
//(we already know how to reverse an array)
void reverse(int arr[], int low, int high){
    while(low<high){
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}
void leftRotateD(int arr[], int n, int d){
    reverse(arr, 0, d-1);  //{2, 1, 3, 4, 5}
    reverse(arr, d, n-1);  //{2, 1, 5, 4, 3}
    reverse(arr, 0, n-1);  //{3, 4, 5, 1, 2}
}
int main() {
      int arr[] = {1, 2, 3, 4, 5}, n = 5, d=2;

      cout<<"Before Rotation"<<endl;
       for(int i = 0; i < n; i++){
       		cout<<arr[i]<<" ";
       }
       cout<<endl;

       leftRotateD(arr, n, d);

       cout<<"After Rotation"<<endl;
       for(int i = 0; i < n; i++){
       		cout<<arr[i]<<" ";
       }
}
//write reverse fn above the leftRotateD fn👀



