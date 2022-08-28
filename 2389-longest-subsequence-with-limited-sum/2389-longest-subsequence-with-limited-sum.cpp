class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int m = queries.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
            nums[i]+=nums[i-1];
        vector<int> ans;
        for(int i=0;i<m;i++){
            int pos = upper_bound(nums.begin(),nums.end(),queries[i]) - nums.begin();
            ans.push_back(pos);
        }
        return ans;
    }
};