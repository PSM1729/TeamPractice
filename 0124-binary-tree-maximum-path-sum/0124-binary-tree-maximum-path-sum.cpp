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
    int ans=INT_MIN;
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        int l=dfs(root->left),r=dfs(root->right);
        int t=max(max(l,r)+root->val,root->val);
        int p=max(t,root->val+l+r);
        ans=max(ans,p);
        return t;
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        dfs(root);
        return ans;
    }
};