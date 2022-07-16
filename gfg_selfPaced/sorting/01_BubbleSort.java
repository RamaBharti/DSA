//we get an array of ascending order elements of an given array
//
class BubbleSort{
    public static void printArray(int arr[]){
        for(int i=0;i<arr.length;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }
    public static void main(String args[]) {
        int arr[]={7,8,3,1,2};
        //BUBBLE SORT, put the largest element at last index
        //time complexity= O(n^2), for sorting not an efficient approach
        for(int i=0;i<arr.length-1;i++){// n-1 times run horha
            for(int j=0;j<arr.length-i-1;j++){
                //length-i-1 means, when scanning loop for the first time, i=0, i.e.no element sorted, for the 2nd time, i=1 and one element is sorted, basically the number of sorted element=i
                if(arr[j]>arr[j+1]){
                    //swap
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
        //print array
        printArray(arr);
    }
}
