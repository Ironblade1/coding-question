class Solution {
public:
    bool isSafe(int row, int col, vector<vector<bool>>& board, int n){
        int x = row;
        int y = col;
        // checking row
        while(y>=0){
            if(board[row][y]==1) return 0;
            y--;
        }
        x = row; y = col;

        //left up diagonal
        while(x>=0 && y>=0){
            if(board[x][y] ==1) return 0;
            x--;
            y--;
        }

        x = row; y = col;
        //right up diagonal
        while(x<board.size() && y>=0){
            if(board[x][y] ==1) return 0;
            x++;
            y--;
        }
        return 1;
    }

    int solve(int col, vector<vector<bool>>& board, int n) {
        if (col == n) {
            return 1;
        }
        
        int count = 0;
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = true;
                count += solve(col + 1, board, n);
                board[row][col] = false;
            }
        }
        
        return count;
    }

    int totalNQueens(int n) {
        int count = 0;
        vector<vector<bool>> board(n, vector<bool>(n, false));
        return solve(0, board, n);
    }
};
