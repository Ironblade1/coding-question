class Solution {
public:
    long long ans ;
    int dfs(int node, unordered_map<int,list<int>> &adj, vector<int> &visi, int seats){
        visi[node]= true;
        int cnt =1;
        for(auto i:adj[node]){
            if(!visi[i]){
                cnt += dfs(i,adj,visi,seats);
            }
        }
        
        int ncar = cnt/seats;
        if(cnt%seats) ncar++;
        if(node != 0) ans += ncar;

        return cnt;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        if(n == 0) return 0;
        ans =0;
        unordered_map<int,list<int>> adj(n+1);
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visi(n+1,0);
        dfs(0,adj,visi,seats);
        return ans;
    }
};