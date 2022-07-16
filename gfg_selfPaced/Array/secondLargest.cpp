#include <iostream>
using namespace std;
//naive approach
//not very naive: its linear time, time comp sol. its just that solution does two traversal of the array
//idea:
//we first find the index of the largest element
//then we find largest among the remaining elements, we compare only those elements which are not equal to the largest element
 
 //first we write the function for finding the largest element

//int getLargest(int arr[], int n){
//    int largest=0;
//   for(int i=0; i<n; i++){
//        if(arr[i]>arr[largest])
//            largest=i;
//    }
//    return largest;
//}
//now we write a fun to find the 2nd largest, 2nd largest might not exist in case of array of single int(also, largest=0) or same integers, that's why: res=-1
/*
int getSecondLargest(int arr[], int n){
    int largest= getLargest(arr, n);
    int res=-1;
    for(int i=0; i<n; i++){
        if(arr[i]!=arr[largest]){
            if(res==-1)
                return i;
            else if(arr[i]>arr[res])
                return i;
        }
    }
    return res;
}
int main(){
    int arr[]={5, 8, 20, 10};
    cout<<getSecondLargest(arr, 4);
    return 0;
}
*/

//efficient approach : one traversal
//idea: if we consider our array as a stream of data and we traverse this stream from left to right, we can always kee track of largest and 2nd largest till this point
//compute largest and 2nd largest for a1, a2, a3,.., a(i-1) in const time
// three cases:
//1.a[i]>a[largest] : res=largest, largest=i
//2.a[i]==a[largest]: ignore
//3.a[i]<a[largest] (3 cases):
//i. res==-1: res=i
//ii. a[i]<=a[res]: ignore
//iii. a[i]>a[res]: res=i (res is 2nd largest)
int getSecondLargest(int arr[], int n){
    int res=-1, largest=0;
    for(int i=0; i<n; i++){
        if(arr[i]>arr[largest]){
            res=largest;
            largest=i;
        }else if(arr[i]!=arr[largest]){
            if(res==-1|| arr[i]>arr[res])
                res=i;
        }
    }
    return res;
}
int main(){
    int arr[]={5, 8, 20, 10};
    cout<<getSecondLargest(arr, 4);
    return 0;
}
