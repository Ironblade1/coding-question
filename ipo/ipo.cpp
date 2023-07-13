class Solution {
public:
    static bool cmp(pair<int,int>& a, pair<int,int>& b){
        // if(a.first == b.first){
        //     return a.second > b.second;
        // }
        return a.first < b.first;
    }

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> proj;
        for(int i=0;i<profits.size();i++){
            proj.push_back({capital[i],profits[i]});
        }

        sort(proj.begin(),proj.end(),cmp);

        priority_queue<int> pq;
        int n = proj.size();
        int i = 0;
        while (k > 0) {
            while(i<n && w >= proj[i].first) {
                pq.push(proj[i].second);
                i++;
            }
            if(!pq.empty()){
                w+= pq.top();
                pq.pop();
            }
            k--;
        }

        return w;
    }
};