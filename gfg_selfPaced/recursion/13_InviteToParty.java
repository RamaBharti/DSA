//Find the number of ways in which n people can be invited to a party, single or in pair.
//when single guest is invited, now we have n-1 calls left to invite other remaining guests
//when in pair is invited, for 1 person, we have n-1 choices to make a pair, after this n-2 calls left to invite other remaining guests
public class InviteToParty {
    public static int callGuest(int n){
        if(n<=1){
            return 1;
        }
        //single
        int ways1=callGuest(n-1);
        //pair
        int ways2=(n-1)*callGuest(n-2);

        return ways1+ ways2;
    }
    public static void main(String args[]){
        int n=4;
        System.out.println(callGuest(n));
    }
}
