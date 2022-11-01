class Solution {
public:
     bool isValid(int rowsize,int colsize,int currow,int currcolo){
        if(currow<0 || currcolo<0 || currow>=rowsize || currcolo>=colsize)
            return false;
        
        return true;
    }
    int dfs(vector<vector<int>>& grid,int r,int c,int row,int col){
        if(r==row)
            return c;   
        
        if(isValid(row,col,r,c)){      
            if(grid[r][c]==1){
                if(isValid(row,col,r,c+1) && grid[r][c+1]==1)     
                    return dfs(grid,r+1,c+1,row,col);                  
            }
            else{
                if(isValid(row,col,r,c-1) && grid[r][c-1]==-1)  
                    return dfs(grid,r+1,c-1,row,col);                                                 
            }
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        vector<int> ans(col);
        for(int c=0;c<col;c++)
            ans[c]=dfs(grid,0,c,row,col);
        
        return ans;
    }
};