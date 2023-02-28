#include <set>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    string solve(TreeNode* root, unordered_map<string,int> &mp, vector<TreeNode*> &ans){
        if(!root) return "";

        string s = to_string(root->val) + "#" + solve(root->left,mp,ans) + "#" + solve(root->right,mp,ans);
        
        mp[s]++;
        if(mp[s]==2) ans.push_back(root);
        return s;
    }
    
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> mp;
        vector<TreeNode*> ans;
        solve(root,mp,ans);
        return ans;
    }
};