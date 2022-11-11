class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();
        if(n==0)
            return 0;
        int i=0;
        for(int k=1;k<n;k++){
            if(nums[k]!=nums[i]){
                nums[++i]=nums[k];
            }
        }
        return i+1;
    }
};