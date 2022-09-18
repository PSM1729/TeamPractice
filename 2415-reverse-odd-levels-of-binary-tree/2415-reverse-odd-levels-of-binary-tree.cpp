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
    TreeNode* insertValue(TreeNode* root, int value, queue<TreeNode*>& q){
        TreeNode* node = new TreeNode(value);
        if(root==NULL)
            root=node;

        else if(q.front()->left==NULL)
            q.front()->left=node;

        else{
            q.front()->right=node;
            q.pop();
        }
        q.push(node);
        return root;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        bool iso = false;
        while(!q.empty()){
            int k = q.size();
            vector<int> tmp;
            for(int i=0;i<k;i++){
                auto it = q.front();
                q.pop();
                tmp.push_back(it->val);
                if(it->left)
                    q.push(it->left);
                
                if(it->right)
                    q.push(it->right);
            }
            if(iso==false){
                iso = true;
                for(int i=0;i<tmp.size();i++)
                    ans.push_back(tmp[i]);
            }
            else{
                iso = false;
                for(int i=tmp.size()-1;i>=0;i--)
                    ans.push_back(tmp[i]);
            }
        }
        TreeNode* tr = NULL;
        for(int i=0;i<ans.size();i++){
          tr = insertValue(tr, ans[i], q);
        }
        return tr;
    }
};