class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        if(n==2)
            return "11";
        
        string ans="11";
        for(int i=3;i<=n;i++){
            string t="";
            int j=1,cnt=1;
            while(j<ans.size()){
                if(ans[j-1]!=ans[j]){
                    t+=to_string(cnt)+ans[j-1];
                    cnt=1;
                }
                else{
                    cnt++;
                }
                j++;
            }
            t+=to_string(cnt)+ans[j-1];
            ans=t;
        }
        return ans;
    }
};