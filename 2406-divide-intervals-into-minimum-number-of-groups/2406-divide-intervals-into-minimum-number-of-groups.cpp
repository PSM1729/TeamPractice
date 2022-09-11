class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n;
        for(int i=0;i<intervals.size();i++)
            n = max(n, intervals[i][1]);
        
        vector<int> v(n+2, 0);
        for(int i=0;i<intervals.size();i++)
        {
            v[intervals[i][0]]++;
            v[intervals[i][1]+1]--;
        }
        for(int i=1;i<v.size();i++)
            v[i] = v[i] + v[i-1];
        
        int ans = INT_MIN;
        for(int i=0;i<v.size();i++)
            ans = max(ans, v[i]);
        
        return ans;
    }
};