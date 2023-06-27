class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> hp;
        vector<vector<int>> res;

        int n = nums1.size();
        int m = nums2.size();
        for(int i=0;i<n;i++){
            hp.push({nums1[i]+nums2[0], 0});
        }

        while(k>0 && !hp.empty()){
            auto top = hp.top();
            hp.pop();
            int sum = top.first;
            int ind = top.second;

            res.push_back({sum-nums2[ind],nums2[ind]});

            if(ind+1<m){
                hp.push(make_pair(sum-nums2[ind]+nums2[ind+1], ind+1));
            }
            k--;
        }
        return res;
    }
};