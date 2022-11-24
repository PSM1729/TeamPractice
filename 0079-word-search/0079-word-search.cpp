class Solution {
public:
    bool check(vector<vector<char>>& board,int i, int j, string word, int k){
        if(k==word.length())
            return true;
        if(i<0 ||j<0|| i>=board.size()|| j>=board[0].size())
            return false; 
        if(board[i][j]!=word[k])
            return false;
        char s=board[i][j];
        board[i][j]='*';
        bool ans=check(board,i-1,j,word,k+1)|| check(board,i+1,j,word,k+1) ||
            check(board,i,j-1,word,k+1)|| check(board,i,j+1,word,k+1);
        board[i][j]=s;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(check(board,i,j,word,0))
                    return true;
            }
        }
        return false;
    }
};