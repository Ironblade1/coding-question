class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> graph;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double w = succProb[i];

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<double> dist(n, 0.0);
        dist[start] = 1.0;

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});

        while (!pq.empty()) {
            double currProb = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (u == end) {
                return currProb;
            }

            for (const auto& neighbor : graph[u]) {
                int v = neighbor.first;
                double wt = neighbor.second;
                double newProb = currProb * wt;

                if (newProb > dist[v]) {
                    dist[v] = newProb;
                    pq.push({newProb, v});
                }
            }
        }

        return 0.0; // No path from start to end
    }
};
