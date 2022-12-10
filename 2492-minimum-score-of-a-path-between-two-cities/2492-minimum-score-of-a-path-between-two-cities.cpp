class Solution {
public:
    void dfs(int node, vector<pair<int,int>> g[] , vector<int> &vis){
        vis[node] = 1; 
        for(auto it : g[node]) {
            if(!vis[it.first]) 
                dfs(it.first, g, vis); 
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> g[n+1];
        for(auto it: roads){
            g[it[0]].push_back({it[1],it[2]});
            g[it[1]].push_back({it[0],it[2]});
        }
        vector<int> vis(n+1, 0);
        dfs(1,g,vis);
        int mans = INT_MAX;
        for(auto it: roads){
            if(vis[it[0]] && vis[it[1]]){
                mans = min(mans, it[2]);
            }
        }
        return mans;
    }
};