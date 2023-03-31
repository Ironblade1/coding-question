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

    vector<int> dfs(TreeNode* root,int d, int& cnt){
        if(root==NULL) return {};
        if(root->left == NULL && root->right == NULL) return {0};

        vector<int> leftDist = dfs(root->left,d,cnt);
        vector<int> rightDist = dfs(root->right, d,cnt);

        vector<int> distances;
        for(int i=0;i<leftDist.size();i++){
            for(int j=0;j<rightDist.size();j++){
                if(leftDist[i]+rightDist[j]+2 <= d) cnt++;
            }
        }

        for(auto i:leftDist){
            // if(i+1<d)
                distances.push_back(i+1);
        }
        for(auto i:rightDist){
            // if(i+1<d)
               distances.push_back(i+1);
        }
        return distances;
    }

    int countPairs(TreeNode* root, int distance) {
        int cnt =0;
        dfs(root,distance,cnt);
        return cnt;
    }
};