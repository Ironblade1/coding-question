class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int inc = true;
        int dec = true;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]) dec = false;
            else if(nums[i]<nums[i-1]) inc = false;
        }
        return dec || inc;
    }
};