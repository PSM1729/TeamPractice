class Solution {
public:

    vector<int> closestPrimes(int left, int right) {
        vector<bool> is_prime(1000001, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= 1000000; i++) {
            if (is_prime[i] && (long long)i * i <= 1000000) {
                for (int j = i * i; j <= 1000000; j += i)
                    is_prime[j] = false;
            }
        }
        vector<int> pmn;
        for(int i=left;i<=right;i++){
            if(is_prime[i])
                pmn.push_back(i);
        }
        int pv = -1, nt = -1, md = INT_MAX;
        for(int i=1;i<pmn.size();i++){
            int dff = pmn[i] - pmn[i-1];
            if(dff < md){
                md = dff;
                pv = pmn[i-1];
                nt = pmn[i];
            }
        }
        return {pv,nt};
    }
};