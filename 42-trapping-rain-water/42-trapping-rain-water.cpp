class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1, lmax = 0, rmax = 0;
        int agua = 0;
        while(l<=r){
            if(height[l] <= height[r]){
                if(height[l] >= lmax)
                    lmax = height[l];
                else
                    agua+=lmax - height[l];
                l++;
            }
            else{
                if(height[r] >= rmax)
                    rmax = height[r];
                else
                    agua+=rmax - height[r];
                r--;
            }
        }
        return agua;
    }
};