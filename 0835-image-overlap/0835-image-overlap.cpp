class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<vector<int>> am,pm;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1)
                    am.push_back({i,j});
                if(img2[i][j]==1)
                    pm.push_back({i,j});
            }
        }
        int ans=0;
        map<pair<int,int>,int> mp;
        for(auto i: am){
            for(auto j: pm){
                int xd = i[0]-j[0], yd = i[1]-j[1];
                mp[{xd,yd}]++;
                ans = max(ans, mp[{xd,yd}]);
            }
        }
        return ans;
    }
};