class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal=prices[0],ans=0;
        for(int i=1;i<prices.size();i++){
            minVal=min(minVal,prices[i]);
            ans=max(ans,prices[i]-minVal);
        }
        return ans;
    }
};