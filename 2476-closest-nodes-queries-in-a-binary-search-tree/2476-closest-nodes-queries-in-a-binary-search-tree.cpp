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
    vector<int> ino;
    int lowerBound(int num){
        int s=0,e=ino.size()-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(ino[mid]<=num)
                s=mid+1;
            else
                e=mid-1;
        }
        return e;
    }
    int upperBound(int num){
        int s=0,e=ino.size()-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(ino[mid]>=num)
                e=mid-1;
            else
                s=mid+1;
        }
        return s;
    }
    void inorder(TreeNode* root){
        if(root==NULL)
            return;
        inorder(root->left);
        ino.push_back(root->val);
        inorder(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        inorder(root);
        int n=queries.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            int it = upperBound(queries[i]);
            int it2 = lowerBound(queries[i]);
            if(it2>=0 && it2<ino.size() && ino[it2]<=queries[i]) 
                it2 = ino[it2];
            else 
                it2 = -1;
            if(it>=0 && it<ino.size() && ino[it]>=queries[i]) 
                it = ino[it];
            else 
                it = -1;
            ans.push_back({it2,it});
        }
        return ans;
    }
};