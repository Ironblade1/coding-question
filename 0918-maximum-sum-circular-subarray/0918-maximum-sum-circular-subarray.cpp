class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        int maxSum = INT_MIN;
        int tempMax = 0;

        int minSum = INT_MAX;
        int tempMin = 0;

        int Tsum = 0;
        for(int i=0;i<n;i++){
            Tsum += nums[i];
            tempMax += nums[i];
            maxSum = max(maxSum,tempMax);
            if(tempMax < 0) tempMax = 0;

            tempMin += nums[i];
            minSum = min(minSum, tempMin);   
            if(tempMin>0) tempMin = 0;
        }
        if(Tsum == minSum) return maxSum;
        else return max(maxSum,Tsum - minSum);
   }
};
