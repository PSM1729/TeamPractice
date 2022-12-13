class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        vector<vector<int>> dp(r,vector<int>(c,0));
        for(int i=0;i<c;i++)
            dp[0][i]=matrix[0][i];
        
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
                if(j==0)
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
                else if(j==c-1)
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j-1],dp[i-1][j]);
                else
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1]));                
            }
        }
        /*for(auto i: dp)
            for(auto j: i)
                cout<<j<<" ";
            cout<<endl;*/
        int ans=INT_MAX;
        for(int i=0;i<c;i++)
            ans=min(ans,dp[r-1][i]);
        
        return ans;
    }
};