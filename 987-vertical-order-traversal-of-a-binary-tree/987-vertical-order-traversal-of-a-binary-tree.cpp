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
     void preOrder(TreeNode * root, int level, int horiDist, map<int, vector<pair<int, int>>>& map) {
        if(root == nullptr) 
            return;
        map[horiDist].push_back({level, root->val});
        preOrder(root->left, level + 1, horiDist - 1, map);
        preOrder(root->right, level + 1, horiDist + 1, map);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> map;
        preOrder(root, 0, 0, map);
        vector<vector<int>> vertTraversal;
        for(auto &entry : map) {
            sort(entry.second.begin(), entry.second.end());
            vector<int> vertical;
            for(auto &pair : entry.second) {
                vertical.push_back(pair.second);
            }
            vertTraversal.push_back(vertical);
        }
        
        return vertTraversal;
    }
};