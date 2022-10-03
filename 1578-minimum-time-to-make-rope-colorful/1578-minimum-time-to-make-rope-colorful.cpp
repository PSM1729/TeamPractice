class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            char temp=colors[i];
            int mx=neededTime[i];
            i++;
            while(colors[i]==temp){
                if(neededTime[i]>mx){
                    ans+=mx;
                    mx=neededTime[i];
                }
                else
                    ans+=neededTime[i];
                i++;
            }
            i--;
        }
        return ans;
    }
};