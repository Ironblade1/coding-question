class Solution {
public:
    bool checkCycle(int i, unordered_map<int, vector<int>>& adj, vector<bool>& visited, vector<bool>& dfsVisited) {
        visited[i] = true;
        dfsVisited[i] = true;

        for (int neighbor : adj[i]) {
            if (!visited[neighbor] && checkCycle(neighbor, adj, visited, dfsVisited))
                return true;
            else if (dfsVisited[neighbor])
                return true;
        }

        dfsVisited[i] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        for (const auto& prerequisite : prerequisites) {
            adj[prerequisite[0]].push_back(prerequisite[1]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> dfsVisited(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && checkCycle(i, adj, visited, dfsVisited))
                return false;
        }

        return true;
    }
};
