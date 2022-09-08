class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int r=0,s=0,cnt0=0,ans=0;
        while(r<nums.size()){
            if(nums[r]==0)
                cnt0++;
            
            while(cnt0>k){
                if(nums[s]==0)
                    cnt0--;
                
                s++;
            }
            ans=max(ans,r-s+1);
            r++;
        }
        return ans;
    }
};