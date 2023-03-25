class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int> inc = nums;
        sort(inc.begin(),inc.end());
        vector<int> dec = nums;
        sort(dec.rbegin(),dec.rend());
        if(nums== inc || nums== dec) return 1;
        return 0;
    }
};