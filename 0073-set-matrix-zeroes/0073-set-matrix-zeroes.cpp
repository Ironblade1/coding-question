class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int ,int>> zero; //  row,col
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    zero.push_back(make_pair(i,j));
                }
            }
        }
        for(auto i:zero){
            int row = i.first;
            int col = i.second;
            for(int i=0;i<m;i++){
                matrix[i][col]=0;
            }
            for(int i=0;i<n;i++){
                matrix[row][i]=0;
            }
        }
        
    }
};