class Solution {
public:
    bool dfs(int node, unordered_map<int,list<int>> &mp, vector<bool>& visi, stack<int>& st,vector<bool>& dfsvisi){
        visi[node]=1;
        dfsvisi[node] = 1;
        for(auto nbr:mp[node]){
            if(!visi[nbr])
                dfs(nbr,mp,visi,st,dfsvisi);
            if(visi[nbr] && dfsvisi[nbr]) return true;
        }
        st.push(node);
        dfsvisi[node]=false;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> mp;
        for(auto p:prerequisites){
            mp[p[1]].push_back(p[0]);
        }
        stack<int> st;
        vector<int> ans;
        vector<int> res;
        vector<bool> dfsvisi(numCourses,0);
        vector<bool> visi(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visi[i]){
                bool isCyclic = dfs(i,mp,visi,st,dfsvisi);
                if(isCyclic) return {}; //empty vector
            }  
            
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};