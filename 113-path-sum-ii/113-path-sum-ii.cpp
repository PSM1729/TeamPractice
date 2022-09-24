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
    vector<vector<int>> ans;
    vector<int> l;
    void bt(TreeNode* root, int targetSum){
        if(root==NULL) // if root is NULL return
            return;
        l.push_back(root->val); // push the current element 
        if(targetSum==root->val && root->left==NULL && root->right==NULL) // Condition check
            ans.push_back(l);                                             // if satisfy push it
        bt(root->left,targetSum-root->val);                               // go to left part
        bt(root->right,targetSum-root->val);                              // go to right part
        l.pop_back(); // backtrack to present
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        bt(root,targetSum); //backtrack to find the solution
        return ans;
    }
};

/*Basic algo of backtracking:
1. Push the current element
2. Work on next element and check whether it satifies our condition
3. Backtrack the current element
*/