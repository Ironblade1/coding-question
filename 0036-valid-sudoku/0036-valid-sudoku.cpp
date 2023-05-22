class Solution {
public:
    bool isSafe(int row,int col,vector<vector<char>> &sudoku, char val){
        for(int i=0;i<sudoku[0].size();i++){
            //chcking row
            if(sudoku[row][i] == val && i!=col) return false;
            // for chcking column
            if(sudoku[i][col] == val && i!= row) return false;
            // for 3*3 matrix
            if(sudoku[3*(row/3)+i/3][3*(col/3)+i%3] == val && 3*(row/3)+i/3 != row && 3*(col/3)+i%3 != col) return false; 
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    // for(int k=0;k<9;k++){
                    //     if(board[i][k] == board[i][j])
                    //         return 0;
                    //     if(board[k][j] == board[i][j])
                    //         return 0;
                    //     if(board[3*(i/3)+k/3][3*(j/3)+k%3] == board[i][j]) 
                    //         return 0;
                    // }

                    if(!isSafe(i,j,board,board[i][j])){
                        cout<<i<<","<<j;
                        return false;
                    }
                }
            }
        }
        return 1;
    }
};