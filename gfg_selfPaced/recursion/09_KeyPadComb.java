/*Print Keypad Combinations
 */
//in susequences que, choices were fixed, i.e. 2
//here choices are variable
//first of all we will create a map or our keypad(just like we had on our nokia cellphone)
public class KeyPadComb {
    public static String[] keypad= {".", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

    public static void printComb(String str, int idx, String combination/*newString*/){
        if(idx==str.length()){
            System.out.println(combination);
            return;
        }
        char currChar=str.charAt(idx);
        String mapping= keypad[currChar-'0'];

        for(int i=0; i<mapping.length(); i++){
            printComb(str, idx+1, combination+mapping.charAt(i));
        }
    }
    public static void main(String args[]){
        String str="23";
        printComb(str, 0, "");
    }
}
//time comp
//max no. of choices=4 (ijn case of "6"-pqrs)
//time comp=O(no.OfChoices^n), n=str.length() = O(4^n).
