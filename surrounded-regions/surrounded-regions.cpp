class Solution {
public:

    void dfs(int i, int j, vector<vector<char>>& board){
        int m = board.size();
        int n = board[0].size();
        // base case
        if(i>=m || i<0 || j>=n || j<0 || board[i][j]=='X' || board[i][j]=='Z') return ;
        board[i][j]='Z';
        // move up->right->down->left
        dfs(i-1,j,board);
        dfs(i,j+1,board);
        dfs(i+1,j,board);
        dfs(i,j-1,board);
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || j==0 || i==m-1 || j==n-1) && board[i][j]=='O'){  // finding boundary zero
                    dfs(i,j,board); // call dfs for boundary zero and mark all boundary zero to 'Z'
                }
            }
        }

        // step-3 convert rest of all zero  to X and convert all 'Z' to O;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j] = 'X';
                if(board[i][j]=='Z') board[i][j] = 'O';
            }
        }
    }
};