class Solution {
public:
    int ans = 0;
    int covered(vector<vector<int>>& mat){
        int cnt = 0;
        for(int i=0;i<mat.size();i++){
            bool flg = true;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1)
                    flg = false;
            }
            if(flg == true)
                cnt++;
        }
        return cnt;
    }
    int bt(vector<vector<int>>& mat, int cols, int c){
        if(c==mat[0].size() || cols==0){
            int tp = covered(mat);
            ans = max(ans, tp);
            return tp;
        }
        int x = bt(mat,cols,c+1); //not select
        vector<vector<int>> tmp = mat;
        for(int i=0;i<mat.size();i++)
            tmp[i][c] = 0;
        int y = bt(tmp,cols-1,c+1); //select
        return max(x,y);
    }
    int maximumRows(vector<vector<int>>& mat, int cols) {
        bt(mat,cols, 0);
        return ans;
    }
};