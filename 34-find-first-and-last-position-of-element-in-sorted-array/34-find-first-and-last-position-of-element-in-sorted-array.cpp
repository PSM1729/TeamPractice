class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=r+(l-r)/2;
            //cout<<l<<r<<" ";
            if(nums[mid]==target){
                int i=mid,j=mid;
                while(i>=0 && nums[i]==target)
                    i--;
                while(j<nums.size() && nums[j]==target)
                    j++;
                
                ans[0]=i+1;ans[1]=j-1;
                break;
            }
            else if(nums[mid]>target){
                r=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
        }
        return ans;
    }
};