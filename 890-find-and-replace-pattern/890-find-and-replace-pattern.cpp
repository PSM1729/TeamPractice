class Solution {
public:
    vector<int> decode(string pattern){
        int n =  pattern.length(),cnt=0;
        unordered_map<char,int> mp;
        vector<int> pnt;
        for(int i=0;i<n;i++){
            if(mp.find(pattern[i])==mp.end()){
                cnt++;
                mp.insert({pattern[i],cnt});
            }
            pnt.push_back(mp[pattern[i]]);
        }
        return pnt;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<int> pnt = decode(pattern);
        vector<string> ans;
        for(auto it: words){
            if(decode(it)==pnt)
                ans.push_back(it);
        }
        return ans;
    }
};