class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int fcnt=0,ocnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                if(ocnt==0) continue;
                else 
                    fcnt++;
            }
            else
                ocnt++;
            if(fcnt>ocnt)
            fcnt= ocnt;
        }
        return fcnt;
    }
};