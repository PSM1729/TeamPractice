class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& m, int target) {
        int r=m.size(), c=m[0].size(), ans=0;
        for(int i=0;i<r;i++){
            for(int j=1;j<c;j++){
                m[i][j]+=m[i][j-1];
            }
        }
        unordered_map<int,int> mp;
        for(int i=0;i<c;i++) {
            for(int j=i;j<c;j++) {
                mp.clear();
                mp.insert({0,1});
                int cur = 0;
                for(int k=0;k<r;k++) {
                    cur += m[k][j] - (i>0?m[k][i-1]:0);
                    if(mp.find(cur-target)!=mp.end()) 
                        ans+= mp[cur - target];
                    mp[cur]++;
                }
            }
        }
        return ans;
    }
};