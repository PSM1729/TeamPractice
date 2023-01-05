class Solution {
public:
    static bool comp(const vector<int>& vec1, const vector<int>& vec2){
	    return vec1[1] < vec2[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int cnt=1,min=points[0][1];
        for(int i=1;i<points.size();i++){
            if(points[i][0]<=min)
                continue;
            else{
                cnt++;
                min=points[i][1];
            }
        }
        return cnt;
    }
};