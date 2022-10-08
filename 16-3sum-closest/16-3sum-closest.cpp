class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n= nums.size();
        int ans= INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++)
        {
            int l=i+1,r=n-1;
            while(l<r)
            {
                if(abs(1LL*target-ans) > abs(1LL*target-(nums[i]+nums[l]+nums[r])))
                    ans= nums[i]+nums[l]+nums[r];
                else if(nums[i]+nums[l]+nums[r]<target)
                    l++;
                else
                    r--;
            }
        }
        return ans;
    }
};