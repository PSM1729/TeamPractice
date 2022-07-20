class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> pr(n), su(n);
        for(int i=1;i<n;i++){
            if(security[i]<= security[i-1])
                pr[i]=pr[i-1]+1;
            else
                pr[i]=0;
        }
        for(int i=n-2;i>=0;i--){
            if(security[i] <= security[i+1])
                su[i]=su[i+1]+1;
            else
                su[i]=0;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(pr[i]>=time && su[i]>=time)
                ans.push_back(i);
        }
        return ans;
    }
};