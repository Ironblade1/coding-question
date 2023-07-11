class Solution {
public:
    unordered_map<int, TreeNode*> parentMap;
    
    void findParents(TreeNode* node, TreeNode* parent) {
        if (!node)
            return;
        
        parentMap[node->val] = parent;
        
        findParents(node->left, node);
        findParents(node->right, node);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findParents(root, nullptr);
        
        unordered_set<int> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target->val);
        
        int distance = 0;
        while (!q.empty()) {
            if (distance == k) {
                vector<int> result;
                while (!q.empty()) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return result;
            }
            
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (node->left && visited.find(node->left->val) == visited.end()) {
                    q.push(node->left);
                    visited.insert(node->left->val);
                }
                
                if (node->right && visited.find(node->right->val) == visited.end()) {
                    q.push(node->right);
                    visited.insert(node->right->val);
                }
                
                if (parentMap[node->val] && visited.find(parentMap[node->val]->val) == visited.end()) {
                    q.push(parentMap[node->val]);
                    visited.insert(parentMap[node->val]->val);
                }
            }
            
            distance++;
        }
        
        return {};
    }
};
