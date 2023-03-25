class Solution {
public:
    
    int dfs(int node,vector<bool> &visi, vector<vector<int>>& adj){
        visi[node]= true;
        int cnt =1;
        for(auto ngbr:adj[node]){
            if(!visi[ngbr]){
                cnt+= dfs(ngbr,visi,adj);
            }
        }
        return cnt;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        long total = ((long)n*(n-1))/2;
        vector<bool> visi(n,0);
        for(int i=0;i<n;i++){
            if(!visi[i]){
                int node = dfs(i,visi,adj);
                total -= ((long)node*(node-1))/2;
            }
        }
        return total;
    }
};