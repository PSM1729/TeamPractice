class Solution {
public:
    int dfs(vector<int>& nums, int k, vector<int>& dp) {
        if(k == 0) 
            return 1;   
        
        if(dp[k] != -1) 
            return dp[k];
        
        int h = 0;
        for(int x : nums) {
            if(k >= x) {
                h += dfs(nums, k-x, dp);
            }
        }    
        return dp[k] = h; 
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);      
        return dfs(nums, target, dp);
    }
};