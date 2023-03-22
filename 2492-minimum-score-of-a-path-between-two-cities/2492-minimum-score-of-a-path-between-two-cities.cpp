class Solution {
public:

    int dfs(int node,vector<vector<pair<int,int>>>& adj, vector<int>& visi, int& ans){
        visi[node] = 1;
        for(auto& i : adj[node]){
            int v = i.first;
            int w = i.second;
            ans = min(ans, w);
            if(visi[v]==0){
                visi[v] = 1;
                ans = min(ans, dfs(v, adj, visi ,ans));
            }
        }
        return ans;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto road : roads){ 
            int u = road[0];
            int v = road[1];
            int w = road[2];
            adj[u].push_back({v, w}); // u-> {v, dis}
            adj[v].push_back({u, w}); // v-> {u, dis}
        }
        int ans = INT_MAX;
        vector<int> visi(n+1,0);
         dfs(1,adj,visi,ans);
        return ans;
    }
};