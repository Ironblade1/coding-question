#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        unordered_set<char> keySet{'a', 'b', 'c', 'd', 'e', 'f'};
        unordered_set<char> lockSet{'A', 'B', 'C', 'D', 'E', 'F'};

        int keyCount = 0;
        pair<int, int> start;  // (i,j)
        string keyStr;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '@') {
                    start = make_pair(i, j);
                } else if (keySet.count(grid[i][j])) {
                    keyCount++;
                }
            }
        }

        queue<pair<pair<int, int>, string>> q;
        q.push(make_pair(start, keyStr));
        unordered_set<string> visited;
        vector<vector<int>> directions{{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

        auto addAllDirections = [&](int i, int j, const string& keyStr) {
            for (const auto& d : directions) {
                int r = i + d[0];
                int c = j + d[1];

                if (r < 0 || c < 0 || r >= n || c >= m) {
                    continue;
                }
                q.push(make_pair(make_pair(r, c), keyStr));
            }
        };

        int steps = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            for (int l = 0; l < levelSize; l++) {
                pair<pair<int, int>, string> state = q.front();
                q.pop();

                int i = state.first.first;
                int j = state.first.second;
                const string& keyStr = state.second;

                if (visited.count(to_string(i) + "," + to_string(j) + "," + keyStr) || grid[i][j] == '#') {

                    continue;
                }

                char c = grid[i][j];
                if (lockSet.count(c)) {
                    if (keyStr.find(tolower(c)) == string::npos){
                        continue;
                    } else {
                        addAllDirections(i, j, keyStr);
                    }
                } else if (keySet.count(c)) {
                    if (keyStr.find(tolower(c)) == string::npos){
                        string newKeyStr = keyStr + c;
                        if (newKeyStr.size() == keyCount) {
                            return steps;
                        }
                        addAllDirections(i, j, newKeyStr);
                    } else {
                        addAllDirections(i, j, keyStr);
                    }
                } else {
                    addAllDirections(i, j, keyStr);
                }

                visited.insert(to_string(i) + "," + to_string(j) + "," + keyStr);
            }

            steps++;
        }

        return -1;
    }
};
