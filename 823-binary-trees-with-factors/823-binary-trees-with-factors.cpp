class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = 1000000007;
        int n = arr.size();
        unordered_map<long long,long long> mp;
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            mp[arr[i]] += 1;
            for(int j = 0 ; j < i ; j++){
                if(arr[i] % arr[j] == 0){
                    int child1 = arr[j];
                    int child2 = arr[i]/arr[j];
                    if(mp.find(child2) != mp.end()){
                        mp[arr[i]] += (mp[child1] * mp[child2])%mod;
                        mp[arr[i]] %= mod;
                    }
                }
            }
            ans += mp[arr[i]];
            ans %= mod;
        }
        
        return ans;
    }
};