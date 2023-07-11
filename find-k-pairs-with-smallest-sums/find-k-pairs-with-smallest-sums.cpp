class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > hp;
        vector<vector<int>> res;
        int n1 = nums1.size();
        int n2 = nums2.size();

        for(int i=0;i<n1;i++){
            hp.push({nums1[i]+nums2[0],0}); // sum , index of nums2
        }

        while(k>0 && !hp.empty()){
            auto f = hp.top();
            hp.pop();
            int sum = f.first;
            int ind = f.second;

            res.push_back({sum-nums2[ind],nums2[ind]});
            if(ind+1<n2){
                hp.push({sum-nums2[ind]+nums2[ind+1], ind+1});
            }
            k--;
        }
        return res;
    }
};