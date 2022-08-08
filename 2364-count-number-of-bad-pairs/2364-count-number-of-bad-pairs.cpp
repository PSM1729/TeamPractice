#define ll long long
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<ll , ll> mp;
        ll ans = 0, n= nums.size();
        for(int i=0;i<nums.size();i++){
            ll tmp = nums[i]-i;
            if(mp.find(tmp)!=mp.end())
                ans+=mp[tmp];
            mp[tmp]++;
        }
        return (n*(n-1))/2 - ans;
    }
};