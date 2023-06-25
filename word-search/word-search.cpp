class Solution {
public:
    bool flag = 0;
    vector<int> di = {-1,0,1,0};
    vector<int> dj = {0,1,0,-1};

    void solve(int ind,int i,int j,vector<vector<char>>& board, string word){
        int m = board.size();
        int n = board[0].size();
        if(ind == word.size()){
            flag = 1;
            return;
        }
        char val = board[i][j];
        board[i][j] = '#';
        for(int k=0;k<4;k++){
            int new_i = i+ di[k];
            int new_j = j+ dj[k];
            if(new_i<m && new_i>=0 && new_j>=0 && new_j<n && board[new_i][new_j]==word[ind]){
                solve(ind+1,new_i,new_j,board,word);
            }
        }
        board[i][j] = val;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        char f = word[0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==f){
                    solve(1,i,j,board,word);
                }
            }
        }
        return flag;
    }
};