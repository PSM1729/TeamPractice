#define ll long long
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<ll> rem;
        int n = capacity.size();
        for(int i=0;i<n;i++){
            rem.push_back(capacity[i] - rocks[i]);
        }
        sort(rem.begin(), rem.end());
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(rem[i]==0){
                cnt++;
                continue;
            }
            else if(additionalRocks >= rem[i]){
                cnt++;
                additionalRocks-= rem[i];
                rem[i] = 0;
            }
            else if(rem[i] > additionalRocks)
                break;
        }
        return cnt;
    }
};