class Solution {
public:
    set<vector<int>> ans;
    vector<int> ps;
    void bt(vector<int>& nm, int id){
        ans.insert(ps);
        for(int i=id;i<nm.size();i++){
            ps.push_back(nm[i]);
            bt(nm,i+1);
            ps.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        bt(nums,0);
        vector<vector<int>> t;
        for(auto it: ans)
            t.push_back(it);
        return t;
    }
};