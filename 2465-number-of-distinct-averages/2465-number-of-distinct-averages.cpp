class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        set<double> st;
        while(i<j){
            //cout<<(double)(nums[i]+nums[j])/2<<" ";
            st.insert((double)(nums[i]+nums[j])/2);
            i++;j--;
        }
        for(auto it: st)
            cout<<it<<" ";
        return st.size();
    }
};