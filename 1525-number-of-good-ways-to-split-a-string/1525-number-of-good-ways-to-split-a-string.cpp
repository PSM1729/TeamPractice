class Solution {
public:
    int numSplits(string s) {
        int ans = 0;
        vector<int>pre(s.length()),post(s.length());
        unordered_set<char>m1,m2;
        int l = s.length()-1;
        for(int i=0;i<s.length();i++){
            m1.insert(s[i]);
            m2.insert(s[l-i]);
            pre[i]    = m1.size();
            post[l-i] = m2.size();
        }
        for(int i=1;i<=l;i++)
            ans+=(pre[i-1]==post[i]);
        return ans;
    }
};