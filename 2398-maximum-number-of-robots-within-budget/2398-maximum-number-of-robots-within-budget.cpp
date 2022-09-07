class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        long long n = chargeTimes.size(), i = 0, ans = 0, j = 0, rs = 0;
        multiset<int> s;
        while(j<n){
            rs+=runningCosts[j];
            s.insert(chargeTimes[j]);
            
            if(*rbegin(s)+(j-i+1)*rs > budget){
                rs-=runningCosts[i];
                s.erase(s.find(chargeTimes[i++]));
            }

            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};