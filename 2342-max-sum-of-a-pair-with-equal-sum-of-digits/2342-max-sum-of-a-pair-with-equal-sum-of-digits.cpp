class Solution {
public:
    int rds(int num){
        int ans=0;
        while(num>0){
            int r = num%10;
            ans+=r;
            num = num/10;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> s;
        int ans=INT_MIN;
        for(auto i: nums){
            if(s.find(rds(i))!=s.end())
                ans=max(ans, s[rds(i)]+i);
            s[rds(i)] = max(s[rds(i)],i);
        }
        
        return (ans==INT_MIN)?-1: ans;
    }
};