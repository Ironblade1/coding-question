class Solution {
public:
    void dfs(int node,vector<int>&edges,vector<bool>&vis,vector<bool>&extra,vector<int>&dist,int &ans,int distance){
        if(node!=-1){
            if(!vis[node]){
                vis[node]=true;
                extra[node]=true;
                dist[node]=distance;
                dfs(edges[node],edges,vis,extra,dist,ans,distance+1);
            }
            else if(extra[node]){
                ans=max(ans,distance-dist[node]);
            }
            extra[node]=false;
        }
    }
    int longestCycle(vector<int>& edges) {
        vector<bool>vis(edges.size(),false);
        vector<bool>extra(edges.size(),false);
        vector<int>dist(edges.size(),0);
        int ans=-1;
        for(int i=0;i<edges.size();i++){
            if(!vis[i]){
                dfs(i,edges,vis,extra,dist,ans,0);
            }
        }
        return ans;
    }
};