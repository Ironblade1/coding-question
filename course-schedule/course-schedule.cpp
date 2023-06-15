class Solution {
public:
    bool dfs(int node,unordered_map<int,list<int>>& mp, vector<bool>& visi, vector<bool>& dfsvisi){
        visi[node] = 1;
        dfsvisi[node] =1;
        for(auto nbr:mp[node]){
            if(!visi[nbr]){
                dfs(nbr,mp,visi,dfsvisi);
            }
            if(visi[nbr] && dfsvisi[nbr]) return true;
        }
        dfsvisi[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> mp;
        for(auto p:prerequisites){
            mp[p[1]].push_back(p[0]);
        }
        vector<bool> visi(numCourses,0);
        vector<bool> dfsvisi(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visi[i]){
                bool isCyclic = dfs(i,mp,visi,dfsvisi);
                if(isCyclic) return false;  // thier is cycle present in this graaph thats why all course aren't be completed
            }
        }
        return true;
    }
};