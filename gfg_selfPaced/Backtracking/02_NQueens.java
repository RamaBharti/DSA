//N-Queens
//NxN chessboard
//N Queens
//Print all solutions where queens are safe i.e. no any of the two queens attack at each other.
import java.util.ArrayList;
import java.util.List;

public class NQueens {
//isSafe fn, we will check for all the 8 directions
    public static boolean isSafe(int row, int column, char[][] board){
        //horizontal dirc
        for(int j=0; j<board.length; j++){
            if(board[row][j]=='Q'){//at this horizontal line Queen is already there, so not safe to put a queen here
                return false;
            }
        }
        //vertical dirc
        for(int i=0; i<board[0].length; i++){
            if(board[i][column]=='Q'){
                return false;
            }
        }
        //upper left(diagonally)
        int r=row;
        for(int c=column; c>=0&&r>=0; c--, r--){
            if(board[r][c]=='Q'){
                return false;
            }
        } 
        //upper right
        r=row;
        for(int c=column; c<board.length&& r>=0; c++,r--){
            if(board[r][c]=='Q'){
                return false;
            }
        }
        //lower left
        r=row;
        for(int c=column; c>=0&& r<board.length; r++, c--){
            if(board[r][c]=='Q'){
                return false;
            }
        }
        //lower right
        r=row;
        for(int c=column; c<board.length&& r<board.length; c++, r++){
            if(board[r][c]=='Q'){
                return false;
            }
        }
        return true;
    }

    public static void saveBoard(char[][] board,  List<List<String>> allBoards){// 3 step proccess to add
        //1. board mei se ek ek krke saare rows nikal liye 
        //2. we added all the rows in newBoard
        //3. total newBoards are added to allBoards
        String row="";
        List<String> newBoard= new ArrayList<>();

        for(int i=0; i<board.length; i++){  //1. board mei se ek ek krke saare rows nikal liye
            row="";
            for(int j=0; j<board[0].length; j++){
                if(board[i][j]=='Q')
                    row+='Q';
                else
                    row+='.';
            }
            newBoard.add(row);  //2. we added all the rows in newBoard
        }
        allBoards.add(newBoard);  //3. total newBoards are added to allBoards
    }

    //to implement backtrackin(recursion) creating a fn
    //start placing queens in the helper fn, using a loop
        public static void helper(char[][] board,  List<List<String>> allBoards, int column){
            //base case
            if(column==board.length){
                saveBoard(board, allBoards);
                return;
            }
            for(int row=0; row<board.length; row++){
               //check if the position at which Queen is being placed is safe or not 
               if(isSafe(row, column, board)){ //we will be creating this isSafe fn

                board[row][column]='Q';

                //call helper fn for the next queen in the next column
                helper(board, allBoards, column+1);

                //now when we are done with one solution(whether it's correct or not?) we will be looking for another soloution(backtrack basically), so for this, we will have to remove the Queens that we placed before
                board[row][column]='.';
               }
            }
        }

    public static List<List<String>> solveNQueens(int n){ //not a recursive fn
        List<List<String>> allBoards= new ArrayList<>();
        char[][] board= new char[n][n];
         
        helper(board, allBoards, 0); 
        return allBoards;
    }
    public static void main(String args[]){
        int n=4;
        System.out.println(solveNQueens(n));
    }
}
//time comp=O(n*n)
