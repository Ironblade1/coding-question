class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ind1 = 0;
        int ind2 =1;
        int ans = 0;
        if( nums.size()==1) return nums[0];
        while(ind1<nums.size() || ind2<nums.size()){
            if(nums[ind1]!=nums[ind2]) return ans = nums[ind1];
            ind1 = ind2+1;
            ind2=ind1+1;
        }
        return ans;
    }
};