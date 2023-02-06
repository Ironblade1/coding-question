class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n,0);
        vector<int> v1;
        vector<int> v2;
        for(int i=0;i<n;i++){
            v1.push_back(nums[i]);
            v2.push_back(nums[i+n]);
        }
        for(int i=0;i<n;i++){
            ans[2*i] = v1[i];
            ans[2*i+1] = v2[i];
        }
        return ans;
    }
};