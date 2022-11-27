class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> ro, rz, co, cz;
        int m = grid.size(), n = grid[0].size();
        for(int i=0;i<m;i++){
            int on=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                    on++;
            }
            ro.push_back(on);
            rz.push_back(n-on);
        }
        
        for(int i=0;i<n;i++){
            int on=0;
            for(int j=0;j<m;j++){
                if(grid[j][i]==1)
                    on++;
            }
            co.push_back(on);
            cz.push_back(m-on);
        }
        /*for(auto it: rz){
            cout<<it<<" ";
        }*/
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = ro[i]+co[j]-rz[i]-cz[j];
            }
        }
        return ans;
    }
};