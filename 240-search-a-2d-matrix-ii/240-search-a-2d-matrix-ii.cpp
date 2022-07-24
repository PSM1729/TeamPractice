class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(), c = matrix[0].size(), rc = 0;
        int cc = c-1;
        while(rc<=r-1 && cc>=0){
            if(matrix[rc][cc]==target)
                return true;
            else if(matrix[rc][cc] > target)
                cc--;
            else
                rc++;
        }
        return false;
    }
};