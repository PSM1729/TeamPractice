class Solution {
public:
   
    int maxSumSubmatrix(vector<vector<int>>& matrix, int t) {
        int r = matrix.size(), c = matrix[0].size();
        int max_sum = INT_MIN;
        for(int i=0;i<r;i++){
            vector<int> v(c,0);
            for(int j=i;j<r;j++){
                for(int k=0;k<c;k++){
                    v[k]+=matrix[j][k];
                }
                for(int i=0; i<c; i++) {
                    int sum = 0;
                    for(int j=i; j<c; j++) {
                        sum += v[j];
                        if(sum > max_sum && sum <=t) 
                            max_sum = sum;
                    }
                }
            }
        }
        return max_sum;
    }
};