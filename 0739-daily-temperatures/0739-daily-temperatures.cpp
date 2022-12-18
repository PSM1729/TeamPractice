class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        int max_temp = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(temperatures[i]>=max_temp)
            {
                max_temp = temperatures[i];
            }
            else {
                int currday = i,days = 1;
                while(temperatures[currday+days]<=temperatures[currday])
                {
                    days += ans[currday+days];
                }
                ans[currday] = days;    
            }
        }
        return ans;
    }
};