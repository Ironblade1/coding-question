class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(adj[i].size()==0) ans.push_back(i);
        }
        return ans;
    }
};