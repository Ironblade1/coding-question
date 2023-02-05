class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = nums.size();
        int ans ;
        // unordered_map<int, int> mp;
        // for(int i:nums){
        //     mp[i]++;
        // }
        // for(int i=0;i<s;i++){
        //     if(mp[i]>1) ans = i;
        // }
        // 
        
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<s-1;i++){
            if(nums[i]==nums[i+1]) ans = nums[i];
        }
        return ans;
    }
};