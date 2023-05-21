class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visi, queue<pair<int,int>>& q, int i, int j){
        int r = grid.size() , c = grid[0].size();
        if(i>=r || i<0 || j>=c || j<0 || grid[i][j]==0 || visi[i][j]==1){
            return ;
        }
        q.push({i,j});
        visi[i][j] = 1;
        dfs(grid,visi,q,i+1,j);
        dfs(grid,visi,q,i-1,j);
        dfs(grid,visi,q,i,j+1);
        dfs(grid,visi,q,i,j-1);
    }

    int shortestBridge(vector<vector<int>>& grid) {
       int m = grid.size();
       int n = grid[0].size();
       int flips =0;
       queue<pair<int,int>> q;
       vector<vector<bool>> visi(m, vector<bool>(n,0));
        bool flag = 0;

       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(flag ==1) break;
               if(grid[i][j]==1){
                   dfs(grid,visi,q,i,j);
                   flag = 1;
                   break;
               }
           }
       }

        // int flips = 0;
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            int size = q.size();
            
            while (size > 0) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                
                for (const auto& direction : directions) {
                    int newRow = row + direction[0];
                    int newCol = col + direction[1];
                    
                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !visi[newRow][newCol]) {
                        if (grid[newRow][newCol] == 1) {
                            return flips;
                        }
                        
                        q.push({newRow, newCol});
                        visi[newRow][newCol] = true;
                    }
                }
                
                size--;
            }
            
            flips++;
        }
        
        return -1;
    }
};