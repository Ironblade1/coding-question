class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        unordered_map<int,vector<int>> mp;
        vector<int> indegrees(n,0);
        for(auto i:edges){
            mp[i[0]].push_back(i[1]);
            indegrees[i[1]]++;
        }

        queue<int> q; // queue stores zero indegree nodes
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            if(indegrees[i]==0){
                q.push(i);
            }
        }

        vector<vector<int>> cnt(n,vector<int>(26,0));  // store frequency of the node 'i' color occur
        for(int i=0;i<n;i++){
            cnt[i][colors[i]-'a']++;
        } 

        int visi =0;

        while(!q.empty()){
            int front = q.front();
            q.pop();
            visi++;
            for(auto nbr:mp[front]){
                for(int i=0;i<26;i++){
                    if(colors[nbr]-'a' == i){ // jis color pe hmm h wohi color h node(nbr) k 
                        cnt[nbr][i] = max(cnt[nbr][i], cnt[front][i]+ 1);
                    }
                    else{
                        cnt[nbr][i] = max(cnt[nbr][i],cnt[front][i]+0);
                    }
                }
                indegrees[nbr]--;
                if(indegrees[nbr]==0){
                    q.push((nbr));
                }
            }
            maxi = max(maxi, *max_element(cnt[front].begin(),cnt[front].end()));
        }
        return visi==n ? maxi:-1;

    }
};






