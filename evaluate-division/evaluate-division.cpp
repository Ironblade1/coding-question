class Solution {
public:
    void dfs(string s, string d, unordered_map<string,vector<pair<string,double>>>& graph, unordered_map<string, bool> &visi,double& ans, double temp){
        if(visi.count(s)) return ; // its already visited
        if(s == d){
            ans = temp;
            return ;
        }

        visi[s] = 1;
        for(auto nbr:graph[s]){
            dfs(nbr.first,d,graph,visi,ans, temp*nbr.second);
        }
        // return ;
    }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> graph;
        for(int i=0;i<equations.size();i++){
            graph[equations[i][0]].push_back({equations[i][1],values[i]});
            graph[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }

        vector<double> res;

        for(int i=0;i<queries.size();i++){
            string s = queries[i][0];
            string d = queries[i][1];
            unordered_map<string, bool> visi;
            double ans = -1;
            double temp = 1;
            
            if(graph.count(s))
                dfs(s,d,graph,visi,ans,temp);
            res.push_back(ans);
        }
        return res;
    }
};