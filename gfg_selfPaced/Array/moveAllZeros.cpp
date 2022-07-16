#include <iostream>
using namespace std;
//naive approach:
//idea(is simple):
//we traverse the array from left side as soon as we find a 0.
//we again go to the right side of this element 0 and we search for the nonzero element and we SWAP this nonzero with the 0.
/*
void moveZeros(int arr[], int n){
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            for(int j=i+1; j<n; j++){
                if(arr[j]!=0){
                    swap(arr[i], arr[j]);
                    //int temp=arr[i];
                    //arr[i]=arr[j];
                    //arr[j]=temp;
                }
            }
        }
    }
}
int main(){
    int arr[]={10, 5, 0, 0, 8, 0, 30, 0}, n=8;
    cout<<"Before moving 0s"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    moveZeros(arr, n);
    cout<<"After moving 0s"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
*/

//efficient approach: linear time solution, requires only one traversal of the array and takes constant extra spacde
//idea:
//if we traverse the array from left to right and if we have fixed the elements from a0 to a(i-1), and
//since it is one traversal the we should be able to process ai in const time
//eg. {10, 12, 0, 0,...}
//this much (0 to i-1)we have already corrected, ie. moved all 0s to the end
//now a new element after the 2nd 0 'ai'
//have two possibilities: ai==0 or ai!=0
//if ai==0 we dont need to do anything, already in required form
//if ai!=0, we SWAP 

void moveZeros(int arr[], int n){
    int count=0;// count of 1st nonzero element
    for(int i=0; i<n; i++){
        if(arr[i]!=0){
            swap(arr[i], arr[count]);
            count++;
        }
    }
}
int main(){
    int arr[]={10, 5, 0, 0, 8, 0, 30, 0}, n=8;
    cout<<"Before moving 0s"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    moveZeros(arr, n);
    cout<<"After moving 0s"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}