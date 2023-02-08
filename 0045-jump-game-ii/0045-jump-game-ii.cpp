class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach = nums[0];
        int jump = 1;
        int n=nums.size();
        if(n==1)
            return 0;
        int steps=nums[0];
        for(int i=1;i<n;i++){
            maxReach = max(maxReach,i+nums[i]);
            if(i==n-1)
                return jump;
             steps--;
            if(steps==0){
                steps = maxReach-i;
                jump++;
            }
           
            
        }
        return jump;
    }
};