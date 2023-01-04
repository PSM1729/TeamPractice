class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(auto it: tasks){
            mp[it]++;
        }
        int ans = 0;
        for(auto it: mp){
            int sc = it.second;
            //cout<<sc<<" ";
            if(sc==1)
                return -1;
            if(sc%3==0)
                ans+=(sc/3);
            else 
                ans+=(sc/3)+1;
        }
        return ans;
    }
};