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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool rl=true;
        while(!q.empty()){
            int k=q.size();
            vector<int> we;
            for(int i=0;i<k;i++){
                TreeNode* u=q.front();
                q.pop();
                we.push_back(u->val);
                if(u->left)
                    q.push(u->left);
                if(u->right)
                    q.push(u->right);
            }
            if(!rl)
                reverse(we.begin(),we.end());
            
            ans.push_back(we);
            rl=!rl;
        }
        return ans;
    }
};