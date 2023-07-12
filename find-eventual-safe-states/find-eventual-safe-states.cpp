class Solution {
public:
    bool chckCycle(int i, vector<bool>& visi, vector<bool>& dfsVisi, vector<vector<int>>& graph){
        visi[i] = 1;
        dfsVisi[i] = 1;
        for(auto nbr:graph[i]){
            if(!visi[nbr] && chckCycle(nbr,visi,dfsVisi,graph)) return true;
            if(visi[nbr] && dfsVisi[nbr]) return true;
        }
        dfsVisi[i] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visi(n,0);
        vector<bool> dfsVisi(n,0);
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(chckCycle(i,visi,dfsVisi,graph) == false) ans.push_back(i);
        }
        return ans;
    }
};