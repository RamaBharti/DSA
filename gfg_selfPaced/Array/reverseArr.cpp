#include <iostream>
using namespace std;
//idea:
//maintain two index variable: low(1st element) and high(last)
//now we simply swap the elements at these two indices
//after swapping these two indices, we move these indices one position close to each other
void reverse(int arr[], int n){
    int low=0, high=n-1;
    while(low<high){
        int temp=arr[low];
        arr[low]=arr[high];
        arr[high]=temp;

        low++;
        high--;
    }
}
int main(){
    int arr[]={10, 5, 7, 30}, n=4;
    cout<<"Before reverse"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    reverse(arr, n);
    cout<<"After reverse"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}