//merge sort is based on divide and conquer
public class MergeSort{
    //fn to conquer
    public static void conquer(int arr[], int si, int mid, int ei){
        //we will have to create a merged array which is a new memory location
        int merged[]= new int [ei-si+1]; //size of array

        int idx1=si; //tracking  the 1st array
        int idx2=mid+1;  //tracking the 2nd array
        int x=0; //tracking the merged array

        while(idx1<=idx2 && idx2<=ei){
            if(arr[idx1]<=arr[idx2]){
                merged[x]=arr[idx1];
                x++; idx1++;
            }else{
                merged[x++]=arr[idx2++];
            }
        }
        //now if we are done with one array, and still there are some remaining elements in another one then in this case, we will simply copy the elements of other aaray to the merged(sorted) array
        while(idx1<=mid){
            merged[x++]=arr[idx1++];
        }
        while(idx2<ei){  //(idx2<=ei) gives error!
            merged[x++]=arr[idx2++]; //only one of these two while loop will work at a time
        }

        //now, we have to copy the elements of merged array to the original array
        for(int i=0, j=si; i<merged.length; i++, j++){
            arr[j]=merged[i];
        }
    }
    //fn to divide the array
    public static void divide(int arr[], int si, int ei){
        //base case
        if(si>=ei){
            return;
        }
        int mid= si+ (ei-si)/2; //problem with (si+ei)/2-si aur ei dono agar kbhi badi values hui and dono ko add kr diya toh kbhi kbhi woh integer se bahar nikal skti hai, jisse space issue ho skta hai and program hmara ruk skta hai
        divide(arr, si, mid); //divide the array to the left part
        divide(arr, mid+1, ei); //divide the array to the right part
        conquer(arr, si, mid, ei); // add the sorted left and rigth part
    }
    public static void main(String args[]){
        int arr[]={6,3,9,5,2,8};
        int n=arr.length;

        divide(arr, 0, n-1);
        //print
        for(int i=0; i<n; i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
}
