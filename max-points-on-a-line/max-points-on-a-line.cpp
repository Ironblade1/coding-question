class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n < 3) {
            return n; // If the number of points is less than 3, all points lie on the same line.
        }

        int maxPointsOnLine = 0;
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            unordered_map<double, int> mp; // Use unordered_map instead of map for efficiency
            int verticalPoints = 1; // Count of points with the same x-coordinate

            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                
                if (x2 == x1) {
                    verticalPoints++;
                    continue;
                }

                double slope = (double)(y2 - y1) / (x2 - x1); // Correct slope calculation

                if (mp.count(slope)) {
                    mp[slope]++;
                } else {
                    mp[slope] = 2;
                }
            }

            maxPointsOnLine = max(maxPointsOnLine, verticalPoints); // Update maximum points on the same line
            for (auto& it : mp) {
                maxPointsOnLine = max(maxPointsOnLine, it.second );
            }
        }

        return maxPointsOnLine;
    }
};
