class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n, -1); // Initialize all vertices with no color
        vector<bool> visi(n, false); // Initialize all vertices as not visited

        for (int i = 0; i < n; i++) {
            if (!visi[i]) {
                if (!bfs(graph, i, colour, visi)) {
                    return false;
                }
            }
        }

        return true;
    }

private:
    bool bfs(vector<vector<int>>& graph, int start, vector<int>& colour, vector<bool>& visi) {
        queue<int> q;
        q.push(start);
        colour[start] = 0;
        visi[start] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int nbr : graph[curr]) {
                if (!visi[nbr]) {
                    colour[nbr] = !colour[curr];
                    visi[nbr] = true;
                    q.push(nbr);
                } else if (colour[nbr] == colour[curr]) {
                    return false;
                }
            }
        }

        return true;
    }
};
