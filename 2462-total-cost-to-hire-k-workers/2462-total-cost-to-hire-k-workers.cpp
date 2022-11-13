class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;
        priority_queue<int,vector<int>, greater<int>> apq, bpq;
        int i=0,j=costs.size()-1;
        if(i==j)
            return costs[0];
        while(i<candidates && i<j){
            apq.push(costs[i]);
            bpq.push(costs[j]);
            i++;j--;
        }
        int cnt=0;
        while(cnt<k){
            int atp = (apq.size()>0)?apq.top():INT_MAX;
            int btp = (bpq.size()>0)?bpq.top():INT_MAX;
            if(atp<=btp){
                ans+=atp;
                apq.pop();
                if(i<=j)
                    apq.push(costs[i++]);
            }
            else{
                ans+=btp;
                bpq.pop();
                if(i<=j)
                    bpq.push(costs[j--]);
            }
            cnt++;
        }
        return ans;
    }
};