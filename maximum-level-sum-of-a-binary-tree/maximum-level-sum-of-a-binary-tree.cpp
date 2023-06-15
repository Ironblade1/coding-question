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

    void solve(TreeNode* root, map<int,int> &mp, int lvl){
        if(!root) return ;
        mp[lvl] += root->val;
        solve(root->left,mp,lvl+1);
        solve(root->right,mp,lvl+1);
    }

    int maxLevelSum(TreeNode* root) {
        map<int,int> mp; // index, sum
        solve(root,mp,0);
        int ind ;
        int maxi = INT_MIN;
        for(auto i:mp){
            if(maxi<i.second){
                maxi = i.second;
                ind = i.first;
            }
        }
        return ind+1;
    }
};