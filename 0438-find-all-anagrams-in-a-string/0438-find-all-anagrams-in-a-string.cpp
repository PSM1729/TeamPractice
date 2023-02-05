class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length(), m = p.length(), r = 0;
        vector<int> shas(26,0), phas(26,0), ans;
        
        if (n < m)
            return ans;
        
        for(int i=0;i<p.size();i++){
            shas[s[i]-'a']++;
            phas[p[i]-'a']++;
        }
        
        if(shas == phas)
            ans.push_back(0);
        
       
        for(int i=m;i<n;i++){
            shas[s[r]-'a']--;
            shas[s[i]-'a']++;
            
            if(shas == phas)
                ans.push_back(r+1);
            
            r++;
        }
        
        return ans;
    }
};