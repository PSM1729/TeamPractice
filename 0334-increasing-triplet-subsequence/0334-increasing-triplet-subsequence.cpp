class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size(), on = INT_MAX, tw = INT_MAX;
        for(int i=0;i<n;i++){
            if(on>=nums[i])
                on = nums[i];
            else if(tw>=nums[i])
                tw = nums[i];
            else 
                return true;
        }
        return false;
    }
};