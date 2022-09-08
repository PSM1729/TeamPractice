class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int j=0,i=0,n=fruits.size(),ans=0;
        while(j<n){
            mp[fruits[j]]++;
            while(mp.size()>2){
                if(mp[fruits[i]]==1)
                    mp.erase(fruits[i]);
                else
                    mp[fruits[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};