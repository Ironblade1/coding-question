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

    void solve(TreeNode* &root, vector<int> &ans){
        if(root==NULL) return ;
        ans.push_back(root->val);
        solve(root->left,ans);
        solve(root->right,ans);
    }

     void solve2(TreeNode* root, vector<int>& ans) {
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* pred = curr->left;
                while (pred->right != curr && pred->right != NULL) {
                    pred = pred->right;
                }

                if (pred->right == NULL) {
                    pred->right = curr;
                    ans.push_back(curr->val);
                    curr = curr->left;
                } else {
                    pred->right = NULL;
                    curr = curr->right;
                }
            }
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve2(root,ans);
        return ans;
         
    }
};