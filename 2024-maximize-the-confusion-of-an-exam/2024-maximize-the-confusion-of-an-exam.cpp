class Solution {
public:
    int cf(string a, int k, char ch) {
        int r=0,s=0,cnt0=0,ans=0;
        while(r<a.length()){
            if(a[r]==ch)
                cnt0++;
            
            while(cnt0>k){
                if(a[s]==ch)
                    cnt0--;
                
                s++;
            }
            ans=max(ans,r-s+1);
            r++;
        }
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(cf(answerKey,k,'T'),cf(answerKey,k,'F'));
    }
};