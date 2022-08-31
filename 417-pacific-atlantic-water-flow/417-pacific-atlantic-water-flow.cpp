class Solution {
public:
    void dfs(vector<vector<int>>& h,vector<vector<bool>>& v, int i, int j){
        if(v[i][j]==true)
            return;
        
        v[i][j] = true;
        if(i+1<h.size() && h[i+1][j] >= h[i][j])
            dfs(h,v,i+1,j);
        if(i-1>=0 && h[i-1][j] >= h[i][j])
            dfs(h,v,i-1,j);
        if(j+1<h[0].size() && h[i][j+1] >= h[i][j])
            dfs(h,v,i,j+1);
        if(j-1>=0 && h[i][j-1] >= h[i][j])
            dfs(h,v,i,j-1);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int r = heights.size(), c = heights[0].size();
        vector<vector<bool>> atl(r, vector<bool> (c, false));
        vector<vector<bool>> pac(r, vector<bool> (c, false));
        
        for(int i=0;i<c;i++){
            dfs(heights,pac,0,i);
            dfs(heights,atl,r-1,i);
        }
        
        for(int i=0;i<r;i++){
            dfs(heights,pac,i,0);
            dfs(heights,atl,i,c-1);
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(atl[i][j]==true && pac[i][j]==true)
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};