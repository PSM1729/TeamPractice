class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i=0,des=0,n=nums.size();
        while(i<n && i<=des){
            des=max(des,i+nums[i]);
            i++;
        }
        if(i==nums.size())
            return true;
        else
            return false;
    }
};