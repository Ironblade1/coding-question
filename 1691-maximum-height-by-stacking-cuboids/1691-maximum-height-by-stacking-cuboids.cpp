class Solution {
public:
    
    bool check(vector<int> a, vector<int> b){
        if(a[0]>=b[0] && a[1]>=b[1] && a[2]>=b[2]) return true;
        return false;
    }
    
    int solveSO(vector<vector<int>> &nums, int n ){
        vector<int> currRow(n+1, 0);
        vector<int> nextRow(n+1, 0);
        
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int take =0;
                if(prev ==-1 || check(nums[curr],nums[prev])){
                    take = nums[curr][2]+ nextRow[curr+1];
                }
                int notTake = 0+ nextRow[prev+1];
                currRow[prev+1] = max(take,notTake);
            }
            nextRow = currRow;
       }
        return nextRow[0];
        
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &c:cuboids){
            sort(c.begin(),c.end());
        }
        
        sort(cuboids.begin(),cuboids.end());
        
        int n = cuboids.size();
        return solveSO(cuboids,n);
        
    }
};