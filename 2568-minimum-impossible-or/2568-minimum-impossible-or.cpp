class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> sm(nums.begin(),nums.end());
        int ans = 1;
        while(1){
            if(sm.find(ans)==sm.end())
                break;
            
            ans = ans*2;
        }
        return ans;
    }
};