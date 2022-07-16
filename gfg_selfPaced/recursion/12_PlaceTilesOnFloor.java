//Place tiles of size 1xm in a floor of size nxm
//can be solved by dynamic programming in a better approach
public class 12_PlaceTilesOnFloor{
    public static int placeTiles(int n, int m){
        if(n==m){
            return 2;
        }
        if(n<m){
            return 1;
        }
        //if placed vertically
        int vertPlacements=placeTiles(n-m, m);
        //if placed horizontally
        int horPlacements=placeTiles(n-1, m);
        return vertPlacements+ horPlacements;
    }
    public static void main(String args[]){
        int n=4, m=2;
        System.out.println(placeTiles(n, m));
    }
}
