class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }
        string ans = s;
        for(int i=0;i<s.length();i++){
            string tmp = s.substr(i)+s.substr(0,i);
            ans = min(ans,tmp);
        }
        return ans;
    }
};