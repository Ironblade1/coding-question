class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i= 0;
        int j = 0;
        int cnt1 = 0;
        int cnt0 = 0;
        int ans = 0;

        for(int i:nums){
            if(i==1)
                cnt1++;
        }
        if(cnt1==n) return n-1;

        cnt1=0;

        while(i<n && j<n){
            if(cnt0 >1){
                j = i+1;
                ans = max(ans,cnt1);
                cnt0 = 0;
                cnt1 = 0;
            }
            if(nums[j]==1)
                cnt1++;
            if(nums[j]==0){
                if(cnt0==0){
                    i=j;
                }
                cnt0++;            
            }
            j++;
        }
        // if(cnt0==1){
           ans = max(ans, cnt1); 
        // }
        // else
        //     ans = max(ans, cnt1-1);
        return ans;
    }
}; 