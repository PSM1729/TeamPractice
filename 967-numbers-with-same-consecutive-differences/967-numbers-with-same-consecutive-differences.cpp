class Solution {
public:
    void dfs(vector<int>& ans, int N, int& K, int num){
        if(N==0){
            ans.push_back(num);
            return;
        }
        int digit = num%10;
        if(digit + K <=9){
            dfs(ans, N-1, K, num*10 + digit + K);            
        }
        if(digit - K >=0 && K!=0){
            dfs(ans, N-1, K, num*10 + digit - K);            
        }
    }
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> ans;
        
        for(int i=1;i<=9;i++){
            dfs(ans, N-1, K, i);
        }
        return ans;
    }
};