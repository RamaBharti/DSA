//rule- 1-9 only once in each row, column & grid (3x3)
//approach- recursion part
//will cover row by row, covering the 1st cell as (0,0), 2nd as (0,1), 3rd as (0,2) and so on till (8,8)
//first of all for (0,0) cell, we will see for the availble valid choices to put any integer from 1-9, similar process for all other cells
//meanwhile while the proceess, if somehow we fill the incorrect integer in any cell, we will backtrack
//basically we have to check the validity of the sudoku i.e. in any particular cell, if the integer is placed correctly or not.
//empty cell represented as- '.'
public class SudokuPuzzle {
    public static boolean isSafe(char[][] board, int row, int col, int number){
        //row and column
        for(int i=0; i<board.length; i++){
            if(board[i][col]==(char)(number+'0')){
                return false;
            }
            if(board[row][i]==(char)(number+'0')){
                return false;
            }
        }
        //grid, sr-starting row, sc-starting column
        int sr= (row/3)*3; 
        int sc=(col/3)*3;

        for(int i=sr; i<sr+3; i++){
            for(int j=sc; j<sc+3; j++){
                if(board[i][j]==(char)(number+'0')){
                    return false;
                }
            }
        }
        return true;
    }

    //we will create a recursive fn which will return boolean(if we get a valid solution for the sudoku-we get true, otherwise false)
    public static boolean helper(char[][] board, int row, int col){
        //base case when sudoku is solved completely
        if(row==board.length) //board.length-1, gives unexpected output
        {
            return true;
        }
        //1. defining (during the next recursion) new row and new column
        int nrow=0;
        int ncol=0;
        //if col is not the last col i.e  not at the board length then new col will be the next col i.e. col+1 and row will remain the same. otherwise, if col is the last col then we will go for the next row.
        if(col!=board.length-1){
            nrow=row;
            ncol=col+1;
        }else{
            nrow=row+1;
            ncol=0; //as we were at the last col, new col will be at 0.
        }
        //2. if a cell already has the integer placed in it, we will go for the next cell, otherwise if not, we will have choices (1-9) to place there 
        if(board[row][col]!='.'){
            if(helper(board, nrow, ncol)){
                return true;
            }
        }else{
            for(int i=1; i<=9; i++){
                if(isSafe(board, row, col, i)){
                    board[row][col]= (char)(i+'0');
                    if(helper(board, nrow, ncol)){
                        return true;
                    }else{
                        board[row][col]='.'; //jb koi galat number daal diya, we will remove the number and loop firse chalegi for i=2 and so on
                    }
                }
            }
        }
        return false;
        
    }
    public static void solveSudoku(char[][] board){ // not a recursive fn
        helper(board, 0, 0); //starting at first cell (0,0)
        
    }
    public static void main(String args[]){
        char[][] board= 
        {  
            { '5', '3', '.', '.', '7', '.', '.', '.', '.' },  
            { '6', '.', '.', '1', '9', '5', '.', '.', '.' },  
            { '.', '9', '8', '.', '.', '.', '.', '6', '.' },  
            { '8', '.', '.', '.', '6', '.', '.', '.', '3' },  
            { '4', '.', '.', '8', '.', '3', '.', '.', '1' },  
            { '7', '.', '.', '.', '2', '.', '.', '.', '6' },  
            { '.', '6', '.', '.', '.', '.', '2', '8', '.' },  
            { '.', '.', '.', '4', '1', '9', '.', '.', '5' },  
            { '.', '.', '.', '.', '8', '.', '.', '7', '9' }  
        };  
        solveSudoku(board);

        for(int i = 0; i < board.length; i++){
			for(int j = 0; j <board[0].length; j++){
				if(j+1 == board[0].length) {System.out.println(board[i][j]);}
				else {System.out.print(board[i][j] + " ");}
			}
		}
    }
}

/*approach for- isSafe part
check for-
 * 1.row
 * 2.column
 * 3.grid(most importantly)- there are 9 cells in a grid, 
 * i)find starting cell for each grid(two strategies)-
 * a) to find starting cell for the cell(r,c)- ((r/3 * 3), (c/3 * 3))
 * b) ((r-r%3),(c-c%3))
 */

