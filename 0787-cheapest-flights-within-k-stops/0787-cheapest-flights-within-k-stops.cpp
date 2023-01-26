class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> dist(k+2,vector<int>(n,INT_MAX));
        
        for(int i=0;i<=k+1;i++){
            dist[i][src] =0;
        }
        
        for(int i=1;i<=k+1;i++){
            for(auto f:flights){
                int u = f[0];
                int v = f[1];
                int w = f[2];
                if(dist[i-1][u] != INT_MAX && dist[i-1][u]+w<dist[i][v]){
                    dist[i][v] = dist[i-1][u] + w;
                }
            }
        }
        
        if(dist[k+1][dst]!= INT_MAX)    return dist[k+1][dst];
        return -1;
    }
};