class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        int m = grid.size(), n = grid[0].size();
        if(i<0 || i>=m || j>=n || j<0 || grid[i][j]!='1') return ;
        grid[i][j] = '2';
        dfs(grid,i-1,j);//up
        dfs(grid,i,j+1);//right
        dfs(grid,i+1,j);//down
        dfs(grid,i,j-1);//left
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m==0) return 0;
        int no_island = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j]=='1'){
                   dfs(grid,i,j);
                   no_island+=1;
               }
            }
        }
        return no_island;
    }
};