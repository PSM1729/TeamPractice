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
    int minSwaps(vector<int>arr){
        int ans = 0, N = arr.size();
        vector<int>temp = arr;
        unordered_map<int, int> h;

        sort(temp.begin(), temp.end());
        for(int i=0;i<N;i++)
            h[arr[i]]=i;

        for(int i=0;i<N;i++){
            if(arr[i]!=temp[i]){
                ans++;
                int init = arr[i];
                swap(arr[i], arr[h[temp[i]]]);
                h[init] = h[temp[i]];
                h[temp[i]] = i;
          }
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int cnt=0;
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
            cnt+=minSwaps(tmp);
        }
        return cnt;
    }
};














