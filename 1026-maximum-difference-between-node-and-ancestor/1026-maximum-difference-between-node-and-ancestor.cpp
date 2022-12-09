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
    int dfs(TreeNode* root,int mx, int mi){
        if(root==NULL)
            return mx-mi;
        mx=max(mx,root->val);
        mi=min(mi,root->val);
        
        return max(dfs(root->left,mx,mi),dfs(root->right,mx,mi));
    }
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root,INT_MIN,INT_MAX);
    }
};