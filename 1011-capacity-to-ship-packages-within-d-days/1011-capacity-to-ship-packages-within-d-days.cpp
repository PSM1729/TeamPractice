class Solution {
public:
    bool isdoable(vector<int>& weights, int days, int mid){
        int d = 1, tot = 0;
        for(int i = 0; i < weights.size(); i++){
            tot += weights[i];
            if(tot > mid){
                tot = weights[i];
                d++;
            }
            if(d > days)
                return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 0;
        for(int i = 0; i < weights.size(); i++){
            l = max(l, weights[i]);
            r += weights[i];
        }
        
        while(l < r){
            int mid = l + (r - l)/2;
            if(isdoable(weights, days, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};