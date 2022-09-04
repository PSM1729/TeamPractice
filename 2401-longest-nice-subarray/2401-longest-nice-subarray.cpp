class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans=0,i=0,res=0, n=nums.size();
        for (int j=0; j<n;++j) {
            while((ans&nums[j]) > 0)
                ans = ans^nums[i++];
            ans|=nums[j];
            res = max(res, j - i + 1);
        }
        return res;
    }
};