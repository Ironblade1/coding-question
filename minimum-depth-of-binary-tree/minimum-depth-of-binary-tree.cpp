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
    int mini = INT_MAX;

    void dfs(TreeNode* root, int cnt){
        if(root==NULL) return ;
        if(!root->left && !root->right){
            mini = min(mini, cnt);
            return ;
        }
        dfs(root->left,cnt+1);
        dfs(root->right,cnt+1);
    }

    int bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;

        while(!q.empty()){
            int s = q.size();

            for(int i=0;i<s;i++){
                TreeNode* front = q.front();
                q.pop();

                if(!front->left && !front->right) return ans;

                if(front->left){
                    q.push(front->left);
                }
                if(front->right) q.push(front->right);
            }
            ans++;
        }
        return ans;
    }

    int minDepth(TreeNode* root) {
        if(!root) return 0;
        dfs(root,1);
        return mini;
    }
};