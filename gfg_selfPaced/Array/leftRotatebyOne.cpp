#include <iostream>
using namespace std;
//i/p: {1, 2, 3, 4, 5}
//o/p: {2, 3, 4, 5, 1}

//i/p: {30, 5, 20}
//o/p: {5, 20, 30}

//idea:
//we first copy 1st element and do a temporary variable i.e. temp=arr[0]; temp =1 for 1st eg
//now shift every element from 2nd element onward to one position left
void leftRotateOne(int arr[], int n){
    int temp=arr[0];
    for(int i=0; i<n; i++){
        arr[i-1]=arr[i]; //{2, 3, 4, 5, 5}
    }
    arr[n-1]=temp;       //{2, 3, 4, 5, 1}
}
int main() {
      int arr[] = {1, 2, 3, 4, 5}, n = 5;

      cout<<"Before Rotation"<<endl;
       for(int i = 0; i < n; i++){
       		cout<<arr[i]<<" ";
       }
       cout<<endl;

       leftRotateOne(arr, n);

       cout<<"After Rotation"<<endl;
       for(int i = 0; i < n; i++){
       		cout<<arr[i]<<" ";
       }
}

//time comp: theta n
//theta 1 auxiliary space
