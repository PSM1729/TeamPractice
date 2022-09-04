class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char,vector<int>> mp(26);
        for(int i=0;i<s.length();i++){
            mp[s[i]].push_back(i);
        }
        for(auto it: mp){
            int d = it.second[1] - it.second[0]-1;
            //cout<<d<<" "<<it.first - 'a'<<"*";
            if(distance[it.first - 'a']!=d)
                return false;
        }
        return true;
    }
};