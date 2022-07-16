import java.util.HashSet;

//using HashSet-takes multiple emements and keeps a unique copy of them
//we will modify a little in the FindSubsequences code
public class FindUniqueSubsequences {
    public static void subsequences(String str, int idx, String newString, HashSet<String> set){
        if(idx==str.length()){
            if(set.contains(newString)){
                return;
            }else{
                System.out.println(newString);
                set.add(newString);
                return;
            }
        }
        char currChar= str.charAt(idx);

        //to be
        subsequences(str, idx+1, newString+currChar, set);

        //or not to be
        subsequences(str, idx+1, newString, set);
    }
    public static void main(String args[]){
        String str="aaab";
        HashSet<String> set=new HashSet<>();
        subsequences(str, 0, 
        "", set);
    }
}
