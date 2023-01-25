class Solution {
public:
    
    void dfs(vector<int> &edges, int node, vector<bool> &visi, vector<int> &dist){
        visi[node]= true;
        int nbr = edges[node];
        while(nbr!= -1 && !visi[nbr]){
            dist[nbr] = dist[node]+1;
            dfs(edges,nbr,visi,dist);
        }
    }
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        int ans =-1;
        int mini = INT_MAX;
        vector<bool> visi1(n,false),visi2(n,false);
        vector<int>  dist1(n,0), dist2(n,0);
        
        dfs(edges,node1,visi1,dist1);
        dfs(edges,node2,visi2,dist2);
        
        
        for(int node= 0;node<=n-1;node++){
            if(visi1[node] && visi2[node] && mini > max(dist1[node],dist2[node])){
                mini = max(dist1[node],dist2[node]);
                ans = node;
            }
        }
        return ans;
    }
};