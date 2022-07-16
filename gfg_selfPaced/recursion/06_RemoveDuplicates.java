/*make an array of size 26, basically a map array */
/*0=a, 1=b, 2=c, ..*/
/*0 will track if we found a and so on.. 25 will map z */
/*'a'-'a'=0, 'b'-'a'=1, 'c'-'a'=2,... 'z'-'a'=25 */
/*currentChar-'a'=map index */
/*we will store true/false in the map */
/*in the beginning we will strore F in every map, F=char not found */
/*now recursively we will check every index*/
//if T is stored at currChar map
//then currChar won't be added to the newString
//and if F is stored at currChar map
//cureChar will be added to the newString
//and map[position]=true i.e. aage agar dubara whi char milta hai toh fir hame pta chale ki yeh pehle mil chuka hai
public class RemoveDuplicates {
    public static boolean[] map=new boolean[26];
    public static void removeDuplicates(String str, int idx, String newString){
        if(idx==str.length()){
            System.out.println(newString);
            return;
        }
        char currChar=str.charAt(idx);
        if(map[currChar-'a']==true){
            removeDuplicates(str, idx+1, newString);
        }else{
            newString+=currChar;
            map[currChar-'a']=true;
            removeDuplicates(str, idx+1, newString);
        }
    }
    public static void main(String args[]){
        String str="abbccda";
        removeDuplicates(str, 0, "");
    }
}
