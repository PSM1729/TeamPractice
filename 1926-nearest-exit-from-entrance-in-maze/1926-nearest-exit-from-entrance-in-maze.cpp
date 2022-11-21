class Solution {
public:
    typedef tuple<int, int, int> t;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        
        queue<t> q;
        
        q.push({entrance[0], entrance[1], 0});
        
        while(!q.empty()){
            auto [row, col, cnt] = q.front();
            q.pop();
            
            if (row == -1 || row == n || col == -1 || col == m || maze[row][col] == '+') continue;
            
            else if ((row == 0 || row == n - 1 || col == 0 || col == m - 1) && maze[row][col] == '.' && (row != entrance[0] || col != entrance[1])) 
                return cnt;
            
            maze[row][col] = '+';
            q.push({row-1, col, cnt+1});
            q.push({row+1, col, cnt+1});
            q.push({row, col-1, cnt+1});
            q.push({row, col+1, cnt+1});
        }
        return -1;
    }
};