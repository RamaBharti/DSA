//subsequences of "abc" 
//abc, ab_, a_c, a__, _bc, _b_, __c, ___
//means abc, ab, ac, a, bc, b, c, ""
//in order: abc, ab, bc, ac, a, b, c
//newString=" "
//at idx 0, a hai
// there will be two calls:
//when 'a' chooses to come: call1: newString+currChar
//when 'a' doesn't choose to come: call2: newString
public class FindSubsequences{
    public static void subsequences(String str, int idx, String newString){
        if(idx==str.length()){
            System.out.println(newString);
            return;
        }
        char currChar= str.charAt(idx);

        //to be
        subsequences(str, idx+1, newString+currChar);

        //or not to be
        subsequences(str, idx+1, newString);
    }
    public static void main(String args[]){
        String str="abc";
        subsequences(str, 0, 
        "");
    }
}
