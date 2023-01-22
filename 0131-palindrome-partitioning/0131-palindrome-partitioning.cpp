class Solution {
public:
    vector<vector<string>> ans;
    vector<string> f;
    void backtrack(string s,int i){
        if(i==s.length()){
            ans.push_back(f);
            return;
        }
        for(int k=i;k<s.length();k++){
            if(isPalindrome(s,i,k)){
                f.push_back(s.substr(i,k-i+1));
                backtrack(s,k+1);
                f.pop_back();
            }
        }
    }
    bool isPalindrome(string s,int i,int l){
        while(i<=l){
            if(s[i++]!=s[l--])
                return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        backtrack(s,0);
        return ans;
    }
};