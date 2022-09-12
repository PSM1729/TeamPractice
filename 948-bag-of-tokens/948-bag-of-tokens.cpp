class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1,ans = 0, res = 0;
        while(i<=j){
            if(tokens[i]<=power){
                power-=tokens[i];
                ans++;
            }
            else if(tokens[i]>power && ans>0){
                while(power<tokens[i]){
                    power+=tokens[j--];
                    ans--;
                }
                ans++;
                power-=tokens[i];
            }
            i++;
            res = max(res, ans);
        }
        return res;
    }
};