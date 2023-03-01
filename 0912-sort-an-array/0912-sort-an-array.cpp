class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> nums1 = nums;
         sort(nums1.begin(),nums1.end());
        return nums1;
    }
};