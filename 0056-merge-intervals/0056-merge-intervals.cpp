class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0){
            return intervals;
        }

        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        vector<int> tempInt = intervals[0];
        
        for(auto i:intervals){
            if(tempInt[1]>=i[0]){
                tempInt[1] = max(tempInt[1],i[1]);
            }
            else{
                res.push_back(tempInt);
                tempInt = i;
            }
        }
        res.push_back(tempInt);
        return res;
    }
};