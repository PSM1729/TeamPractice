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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            long long tmp = q.size(),s=0;
            for(int i=0;i<tmp;i++){
                auto it = q.front();
                q.pop();
                s+=(it->val);
                if(it->left)
                    q.push(it->left);
                if(it->right)
                    q.push(it->right);
            }
            ans.push_back((double)s/(double)tmp);
        }
        return ans;
    }
};