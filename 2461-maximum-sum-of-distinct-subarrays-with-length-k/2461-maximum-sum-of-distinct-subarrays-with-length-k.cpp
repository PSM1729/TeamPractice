class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        long long s=0,ans=0;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
            s+=nums[i];
        }
        
        if(mp.size()==k)
            ans=max(ans,s);
        for(int i=k;i<nums.size();i++){
            mp[nums[i-k]]--;
            s-=nums[i-k];
            if(mp[nums[i-k]]==0)
                mp.erase(nums[i-k]);
            s+=nums[i];
            mp[nums[i]]++;
            cout<<s<<" ";
            if(mp.size()!=k)
                continue;
            else
                ans=max(ans,s);
        }
        return ans;
    }
};