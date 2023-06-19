class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        queue<string>q;
        unordered_set<string>visited;
        unordered_map<string,int> mp;
        for(auto x:wordList) mp[x] = 1;
        
        q.push(beginWord);
        visited.insert(beginWord);
        
        int cnt = 0;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++){
                string node = q.front();
                q.pop();
                
                if(node == endWord){
                    return cnt+1;
                }
                
                for(char ch :"abcdefghijklmnopqrstuvwxyz"){
                    for(int j=0;j<node.size();j++){
                        if(ch == node[j]) continue;
                        string adjNode = node;
                        adjNode[j] = ch;
                       if(!visited.count(adjNode) && mp[adjNode]){
                q.push(adjNode);
                visited.insert(adjNode);
            }
                    }
                }
            }
             ++cnt;
        }
       return 0; 
    }
};