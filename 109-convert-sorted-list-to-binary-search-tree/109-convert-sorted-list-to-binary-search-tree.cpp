/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* maketree(vector<int> li, int s, int e){
        if(s>e)
            return NULL;
        
        int m = (s+e)/2;
        TreeNode* rt = new TreeNode(li[m]);
        rt->left = maketree(li,s,m-1);
        rt->right = maketree(li,m+1,e);
        return rt;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> li;
        int sz=0;
        while(head!=NULL){
            li.push_back(head->val);
            head=head->next;
            sz++;
        }
        return maketree(li,0,sz-1);
    }
};