#include <iostream>
using namespace std;
//naive approah: O(n^n)
/*
int getLargest(int arr[], int n){
    for(int i=0; i<n; i++){
        bool flag =true;
        for(int j=0; j<n; j++){
            if(arr[j]>arr[i]){
              flag=false;
              break;
            }
        }
        if(flag==true)
        return i;
    }
    return -1;
}
int main(){
    int arr[]={5, 8, 20, 10};
    cout<<getLargest(arr, 4);
    return 0;
}
*/
//efficent approach : the idea is to find the largest element in one traversal
//array : {a1, a2, a3,.., a(i-1), ai}
//we will compare ai with the largest element of the remaining a(i-1) elements

int getLargest(int arr[], int n){
    int res=0;
    for(int i=0; i<n; i++){
        if(arr[i]>arr[res]){
            res=i;
        }
    }
    return res;
}
int main(){
    int arr[]={5, 8, 20, 10};
    cout<<getLargest(arr, 4);
    return 0;
}