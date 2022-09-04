class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        int i=0,j=1,n=nums.size();
        while(j<n){
            int s = nums[i]+nums[j];
            if(mp.find(s)!=mp.end())
                return true;
            mp[s]++;
            i++;j++;
        }
        return false;
    }
};