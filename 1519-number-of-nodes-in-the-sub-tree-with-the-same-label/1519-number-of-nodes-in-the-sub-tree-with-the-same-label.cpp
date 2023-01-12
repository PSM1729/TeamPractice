class Solution {
public:
    vector<vector<int>> g;
    vector<int> dfs(int i, string& lb, vector<int>& ans){
        vector<int> mp(26,0);
        mp[lb[i]-'a']=1;
        ans[i]=1;
        for(auto it: g[i]){
            if(!ans[it]){
                vector<int> tp = dfs(it,lb,ans);
                for(int l=0;l<26;l++)
                    mp[l]+=tp[l];
            }
        }
        ans[i]=mp[lb[i]-'a'];
        return mp;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        g.resize(n,vector<int>{});
        vector<int> ans(n,0);
        for(auto it: edges){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        dfs(0,labels,ans);
        return ans;
    }
};