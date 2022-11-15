class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int cnt = 0, n = nums.size();
        for(int i=0;i<n;i++){
            int thcf = nums[i];
            for(int j=i;j<n;j++){
                thcf = __gcd(thcf,nums[j]);
                if(thcf == k)
                    cnt++;
            }
        }
        return cnt;
    }
};