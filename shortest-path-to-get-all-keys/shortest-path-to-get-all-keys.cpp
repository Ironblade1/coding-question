class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        pair<int,int> start;
        string keyStr = "";
        int cntKey = 0;

        unordered_set<char> keySet = {'a','b','c','d','e','f'};
        unordered_set<char> lockSet = {'A','B','C','D','E','F'};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '@'){
                    start = {i,j};
                }
                if(keySet.count(grid[i][j])) cntKey++;
            }
        }

        queue<pair<pair<int,int>, string>> q;
        q.push({start, keyStr});

        unordered_set<string> visi;
        vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};

        auto addAllDirections = [&](int i, int j, string& keyStr){
            for(auto& d:dir){
                int r = i + d[0];
                int c = j + d[1];

                if (r < 0 || c < 0 || r >= n || c >= m) {
                    continue;
                }
                q.push(make_pair(make_pair(r, c), keyStr));
            }
        };

        int steps = 0;

        while(!q.empty()){
            int level = q.size();
            for(int l=0; l<level; l++){
                auto f = q.front();
                q.pop();
                int i = f.first.first;
                int j = f.first.second;
                keyStr = f.second;

                if(visi.count(to_string(i) + "," + to_string(j) + "," + keyStr) || grid[i][j] == '#'){
                    continue;
                }
                char c = grid[i][j];

                if(lockSet.count(c)){
                    if(keyStr.find(tolower(c)) != string::npos){
                        addAllDirections(i, j, keyStr);
                    }
                }
                else if(keySet.count(c)){
                    if(keyStr.find(c) != string::npos){
                        addAllDirections(i, j, keyStr);
                    }
                    else{
                        keyStr += c;
                        if(keyStr.length() == cntKey) return steps;
                        addAllDirections(i, j, keyStr);
                    }
                }
                else{
                    addAllDirections(i, j, keyStr);
                }

                visi.insert(to_string(i) + "," + to_string(j) + "," + keyStr);
            }
            steps++;
        }
        return -1;
    }
};
