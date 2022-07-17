class Solution {
public:
    int dp[1001][1001] = { 1 };
    int mod = 1e9+7;
    int kInversePairs(int n, int k) {
        if (dp[n][k])
            return dp[n][k];
        for (int N = 1; N <= n; ++N)
            for (int K = 0; K <= k; ++K) {
                dp[N][K] = (dp[N - 1][K] + (K > 0 ? dp[N][K - 1] : 0)) % mod;
                if (K >= N)
                    dp[N][K] = (mod + dp[N][K] - dp[N - 1][K - N]) % mod;
            }
        return dp[n][k];
    }
};