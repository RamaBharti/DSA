public class PermutationBacktrack {
    public static void printPermutation(String str, String perm, int idx/*position to place a char */){
        //we reach the base case when string length becomes zero
        if(str.length()==0){
            System.out.println(perm);
            return;
        }
        for(int i=0;i<str.length(); i++){
            char currChar=str.charAt(i);
            //we will remove the currChar, now other remaining char can be placed
            String newStr=str.substring(0, i)+ str.substring(i+1);
            printPermutation(newStr, perm+currChar, idx+1);
        }
    }
    public static void main(String args[]){
        String str="ABC";
        printPermutation(str, "", 0);
    }
}
//possible combinations=n!
//no of path for a single combination=n
//so time compexity= O(n*n!)
