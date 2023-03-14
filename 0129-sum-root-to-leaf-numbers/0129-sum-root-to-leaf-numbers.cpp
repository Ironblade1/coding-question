#include <string>
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
    int sum =0;
    
    void solve(TreeNode* root, string s){
        if(root== NULL) return ;
         s+= to_string(root->val);
        
        if(!root->left && !root->right) sum += stoi(s);
        solve(root->left,s);
        solve(root->right,s);
    }
    
    int sumNumbers(TreeNode* root) {
        solve(root,"");
        return sum;
    }
};