class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> nh;
        for(int i=0;i<names.size();i++){
            nh.push_back({heights[i],names[i]});
        }
        sort(nh.begin(),nh.end());
        vector<string> ans;
        for(auto it: nh)
            ans.push_back(it.second);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};