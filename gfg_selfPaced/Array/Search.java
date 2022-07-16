//unsorted- O(n), sorted- O(logn)
public class Search{
    public static int searchElement(int arr[], int n, int x){
        for(int i=0; i<n; i++){
            if(arr[i]==x){
                return i;            
            }
        }
        return -1;
    }
    public static void main(String args[]){
        int arr[]={2, 5, 7, 6, 9}, n=5;
        System.out.println(searchElement(arr, n, 7));
    }
}