class Solution {
public:
    vector<vector<string>> ans;
    bool issafe(vector<string>& st, int r, int c, int n){
        //check tht column
	    for(int i=r;i>=0;--i)
            if(st[i][c] == 'Q') 
                return false;
        
        //check the left diagonal
        for(int i=r,j=c;i>=0&&j>=0;--i,--j)
            if(st[i][j] == 'Q') 
                return false;
      
        //check the right diagonal
        for(int i=r,j=c;i>=0&&j<n;--i,++j)
            if(st[i][j] == 'Q')
                return false;
        return true;
    }
    void solve(vector<string>& st, int r, int n){
        if(r==n){
            ans.push_back(st);
            return;
        }
        for(int c=0;c<n;c++){
            if(issafe(st,r,c,n)){
                st[r][c]='Q';
                solve(st,r+1,n);
                st[r][c]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> st(n, string(n, '.'));
        solve(st,0,n);
        return ans;
    }
};