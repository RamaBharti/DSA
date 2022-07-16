public class TowerOfHanoi{
    public static void towerOfHanoi(int n, String src, String helper, String dest){ //src=source, dest=destination
    //step 1: transfer n-1 disks from source to helper
    if(n==1){
        System.out.println("transfer disk "+ n+ " from "+ src+" to "+dest);
        return;
    }
        towerOfHanoi(n-1, src, helper, dest); //here, we have to transfer source to helper i.e. now dest=helper, helper=dest
        System.out.println("transfer disk "+ n+ " from "+ src+" to "+dest); //disk 1 is transferred
        towerOfHanoi(n-1, helper, src, dest); //n-1 disk jo helper mei hain unko transfer krna hai dest wale mei
    }
    public static void main(String args[]){
        int n=4;
        towerOfHanoi(n, "S", "H", "D");
    }
}
