class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long ans = 0;
        vector<long long> sb;
        set<int> nm;
        for(auto it: nums){
            nm.insert(it);
        }
        for(auto it: nm){
            sb.push_back(__builtin_popcount(it));
        }
        sort(sb.begin(),sb.end());
        int l = 0, r = sb.size()-1;
        while(l<r){
			int sum = sb[l] + sb[r];
			if(sum >= k) 
				ans += (r-- - l)*2;
			else 
				l++;
		}
        for(auto i: sb){
            if(i+i>=k)
                ans++;
        }
        return ans;
    }
};