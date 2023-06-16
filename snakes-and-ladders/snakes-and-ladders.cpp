class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        queue<pair<int, int>> q;
        q.push({1, 0});
        visited[n - 1][0] = true;

        while (!q.empty()) {
            auto [curr, move] = q.front();
            q.pop();

            if (curr == n * n)
                return move;

            for (int i = 1; i <= 6; i++) {
                int next = curr + i;
                if (next > n * n)
                    break;

                int row = n - 1 - (next - 1) / n;
                int col = ((next - 1) / n) % 2 == 0 ? (next - 1) % n : n - 1 - (next - 1) % n;

                if (visited[row][col])
                    continue;

                visited[row][col] = true;

                if (board[row][col] != -1) {
                    q.push({board[row][col], move + 1});
                } else {
                    q.push({next, move + 1});
                }
            }
        }

        return -1;
    }
};
