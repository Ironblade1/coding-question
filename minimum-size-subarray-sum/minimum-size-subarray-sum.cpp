class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len = INT_MAX;
        int s = 0;
        int sum =0;
        for(int e =0;e<nums.size();e++){
            sum += nums[e];
            while(sum >= target){
                min_len = min(min_len, e-s+1);
                sum -= nums[s];
                s +=  1;
            }
        }
        return (min_len!= INT_MAX) ? min_len : 0;
    }
};