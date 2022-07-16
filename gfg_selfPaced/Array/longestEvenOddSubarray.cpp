//An interesting array problem to find the length of the longest subarray that has alternating even odd elements.
#include <iostream>
using namespace std;
//naive approach:
//idea:
//we traverse through all the elements, for every element we find out longest alternating subarray that begins with this element and 
//if this longest is more than the result that we found so far the we update the result
/*
int maxEvenOdd(int arr[], int n){
    int res=1;
    for(int i=0; i<n; i++){
        int curr=1;
        for(int j=i+1; j<n; j++){
            if((arr[j]%2==0&&arr[j-1]%2!=0)||(arr[j]%2!=0&&arr[j-1]%2==0)){
                curr++;
            }else{
                break;
            }
        }
        res=max(res, curr);
    }
    return res;
}
int main(){
    int arr[]={5, 10, 20, 6, 3, 8}, n=6;
    cout<<maxEvenOdd(arr, n);
}*/

//efficient approach: O(n) (based on kadence algorithm)
//begin traversing from the second element
//for every element there are two cases:
//either we begin a new subarray or extend the previous subarray
//we extend the previous subarray if current element is alternating with the previous element, and if its not, then we begin a new subarray

int maxEvenOdd(int arr[], int n){
    int res=1;
    int curr=1;
    for(int i=1; i<n; i++){
        if((arr[i]%2==0&&arr[i-1]%2!=0)||(arr[i]%2!=0&&arr[i-1]%2==0)){
            curr++;
            res=max(res, curr);
        }else{
            curr=1;
        }
    }
    return res;
}
int main(){
    int arr[]={5, 10, 20, 6, 3, 8}, n=6;
    cout<<maxEvenOdd(arr, n);
}