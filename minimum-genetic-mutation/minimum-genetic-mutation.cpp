class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q;
        unordered_set<string> visited;

        int cnt = 0;
        q.push(startGene);
        visited.insert(startGene);
        
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                string node = q.front();
                q.pop();
                if (node == endGene) return cnt;

                for (int j = 0; j < node.size(); j++) {
                    char originalChar = node[j];

                    for (char c : {'A', 'C', 'G', 'T'}) {
                        if (c == originalChar) continue;

                        node[j] = c;
                        if (visited.count(node) == 0 && find(bank.begin(), bank.end(), node) != bank.end()) {
                            q.push(node);
                            visited.insert(node);
                        }
                    }

                    node[j] = originalChar; // Restore the original character
                }
            }
            cnt++;
        }

        return -1;
    }
};
