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
    int ans = 0;
    void lng(TreeNode* root, bool il, int st){
        if(root == NULL)
            return;
        
        ans = max(ans,st);
        
        if(il){
            lng(root->left,true,1);
            lng(root->right, false,st+1);
        }
        else{
            lng(root->left,true,st+1);
            lng(root->right, false,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        lng(root,true,0);
        lng(root,false,0);
        return ans;
    }
};