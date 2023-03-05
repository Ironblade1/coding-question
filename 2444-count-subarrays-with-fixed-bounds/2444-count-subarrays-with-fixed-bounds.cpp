class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans =0;
        int prevMinInd =-1;
        int prevMaxInd =-1, j =-1;

        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK) j =i;
            if(nums[i]==minK) prevMinInd = i;
            if(nums[i]==maxK) prevMaxInd = i;
            ans += max(0,min(prevMaxInd,prevMinInd)-j);
        }
        return ans;
    }
};