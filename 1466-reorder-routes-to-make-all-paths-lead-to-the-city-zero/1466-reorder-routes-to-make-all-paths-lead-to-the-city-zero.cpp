class Solution {
public:
    
    void bfs(vector<vector<pair<int,int>>>& adj, vector<bool>& visi, int& ans){
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            visi[p.first] = true;
            ans += p.second;
            for(auto& i:adj[p.first]){
                if(!visi[i.first]) q.push(i);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto i:connections){
            adj[i[0]].push_back({i[1],1});
            adj[i[1]].push_back({i[0],0});
        }
        int ans =0;
        vector<bool> visi(n,0);
        bfs(adj,visi,ans);
        return ans;
    }
};