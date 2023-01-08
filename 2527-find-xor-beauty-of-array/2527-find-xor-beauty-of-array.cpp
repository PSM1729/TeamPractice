class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int vl = nums[0];
        for(int i=1;i<nums.size();i++)
            vl=vl^nums[i];
        return vl;
    }
};