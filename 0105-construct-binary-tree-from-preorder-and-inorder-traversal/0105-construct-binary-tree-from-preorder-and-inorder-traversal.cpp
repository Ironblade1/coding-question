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
    int index =0;
    void Mapping(vector<int>& inorder,unordered_map<int,int> &mp){
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
    }
    
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int inorderStart,int inorderEnd,int n , unordered_map<int,int>& mp){
        if(index>=n || inorderStart>inorderEnd) return NULL;
        
        int element = preorder[index++];
        int position = mp[element];
        TreeNode* root = new TreeNode(element);
        
        root->left = solve(preorder,inorder,inorderStart,position-1,n,mp);
        root->right = solve(preorder,inorder,position+1,inorderEnd,n,mp);
        
        return root;
        
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int,int> mp;
        Mapping(inorder,mp);
        for(int i=0;i<n;i++){
            cout<<mp[inorder[i]]<<",";
        }
        TreeNode* ans = solve(preorder,inorder,0,n-1,n,mp);
        return ans;
    }
};











