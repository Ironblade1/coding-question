class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int ans ;
        // unordered_map<int,int> mp;
        // for(int i:nums)  mp[i]++;
        // for(auto i:mp) if(i.second==1) return i.first;
        // return -1;

        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < 32; i++) {
            int cnt = 0; // number of ones
            for (int j = 0; j < n; j++) {
                if ((nums[j] >> i) & 1 == 1)
                    cnt++;
            }
            cnt = cnt%3;
            if(cnt != 0){
                ans = ans | cnt<<i;
            }
        }
        return ans;
    }
};