class Solution {
public:
    int dfs(vector<vector<int>>& g, int i, int j){
        if(i<0 || i>=g.size() || j<0 || j>=g[0].size() || g[i][j]!=1)
            return 0;
        g[i][j]=2;
        return 1 + dfs(g,i+1,j) + dfs(g,i-1,j) + dfs(g,i,j+1) + dfs(g,i,j-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0, r=grid.size(), c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)
                    ans=max(ans,dfs(grid,i,j));
            }
        }
        return ans;
    }
};