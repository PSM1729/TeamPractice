class Solution {
public:
    bool isVowel(char a){
        if(a =='a' || a =='e' || a =='i'|| a =='o' || a =='u')
            return true;
        
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pf(n,0);
        if(isVowel(words[0][0]) && isVowel(words[0].back()))
            pf[0]=1;
        
        for(int i=1;i<n;i++){
            if(isVowel(words[i][0]) && isVowel(words[i].back()))
                pf[i]=pf[i-1]+1;
            else
                pf[i]=pf[i-1];
        }
        
        vector<int> ans;
        for(auto it : queries){
            int l = it[0], r = it[1];
            if(l>0)
                ans.push_back(pf[r]-pf[l-1]);
            else
                ans.push_back(pf[r]);
        }
        return ans;
    }
};