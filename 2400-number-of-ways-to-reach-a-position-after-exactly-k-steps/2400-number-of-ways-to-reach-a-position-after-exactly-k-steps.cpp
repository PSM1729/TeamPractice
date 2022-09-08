class Solution {
public:
    int mod = 1e9+7;
    
    int find(vector<vector<int>>&dp, int s, int e, int k){
        if(k==0){
            if(s==e)
                return 1;
            return 0;
        }
        if(dp[s][k]!=-1)
            return dp[s][k];
        int a= find(dp, s+1, e, k-1)%mod;
        int b= find(dp, s-1, e, k-1)%mod;
        return dp[s][k] = (a+b)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3000, vector<int>(k+1, -1));
        startPos+=1000;
        endPos+=1000;
        return find(dp, startPos, endPos, k);
    }
};