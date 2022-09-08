class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(auto it: knowledge)
            mp[it[0]]=it[1];
        
        string ans = "";
        int n=s.length(),i=0;
        while(i<n){
            if(s[i]=='('){
                string tmp="";
                i++;
                while(s[i]!=')'){
                    tmp+=s[i++];
                }
                i++;
                if(mp.find(tmp)!=mp.end())
                    ans+=mp[tmp];
                else
                    ans+='?';
            }
            else{
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
};