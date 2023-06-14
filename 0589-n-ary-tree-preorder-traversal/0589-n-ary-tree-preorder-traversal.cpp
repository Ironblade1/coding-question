/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void solve(Node* root, vector<int>& ans){
        if(!root) return ;
        ans.push_back(root->val);
        for(auto child:root->children)
            solve(child,ans);
    }

    void solve2(Node* root, vector<int>& ans){
        Node* curr = root;
        stack<Node*> s;
        s.push(root);
        while(!s.empty()){
            auto node = s.top();
            ans.push_back(node->val);
            s.pop();
            for(int i= node->children.size()-1;i>=0;i--){
                s.push(node->children[i]);
            }
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(!root) return ans;
        solve2(root,ans);
        return ans;
    }
};