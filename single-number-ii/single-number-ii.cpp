class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans ;
        unordered_map<int,int> mp;
        for(int i:nums)  mp[i]++;
        for(auto i:mp) if(i.second==1) return i.first;
        return -1;
    }
};