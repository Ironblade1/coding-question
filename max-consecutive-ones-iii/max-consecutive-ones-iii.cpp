class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, n1 = 0, n0 = 0, len = 0;
        int n = nums.size();
        for(r;r<n;r++){
            if(nums[r]==0) n0++;
            else n1++;
            while(n0>k){
                if(nums[l]==0) n0--;
                else n1--;
                l++;
            }
            len = max(len, r-l+1);
        }
        return len;
    }
};