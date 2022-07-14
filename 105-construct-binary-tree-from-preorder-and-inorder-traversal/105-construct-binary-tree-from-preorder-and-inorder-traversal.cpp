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
    unordered_map<int,int> ump;
    int id=0;
    TreeNode* makeit(vector<int>& preorder, vector<int>& inorder,int l, int r){
        if(l>r)
            return NULL;
        TreeNode* root= new TreeNode(preorder[id++]);
        if(l==r)
            return root;
        
        int mid=ump[root->val];
        root->left=makeit(preorder,inorder,l,mid-1);
        root->right=makeit(preorder,inorder,mid+1,r);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
            ump[inorder[i]]=i;
        
        int n=inorder.size();
        TreeNode* root= makeit(preorder,inorder,0,n-1);
        return root;
    }
};