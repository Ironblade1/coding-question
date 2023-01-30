class Solution {
public:

    int solve1(vector<int>& nums) {
        int n = nums.size();
        int mxSum = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum=0;
                for(int k=i;k<=j;k++){
                    sum += nums[k];
                }
                mxSum = max(sum,mxSum);
            }
        }
        return mxSum;
    }

    int solve2(vector<int>& nums){
        int n= nums.size();
        int maxsum = INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+= nums[i];
            maxsum = max(maxsum,sum);
            if(sum<0)   sum =0;
        }
        return maxsum ;
    }

    int maxSubArray(vector<int>& nums) {
        // return solve1(nums);
        
        // kadane's algorithms
        return solve2(nums);
    }
};