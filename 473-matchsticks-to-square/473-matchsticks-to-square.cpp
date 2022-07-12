class Solution {
public:
    vector<int> si = {0, 0, 0, 0};
    
    bool helper(vector<int>& mt, int i, int n, int tr){
        if(i==n)
            return true;
        
        for(int k=0; k<4; k++){
            if(si[k]+mt[i]<=tr){
                si[k]+=mt[i];
                
                if(helper(mt, i + 1, n, tr))
                    return true;
                
                si[k] -= mt[i];
            }
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size(),sum = 0;
        sum = accumulate(matchsticks.begin(),matchsticks.end(),0);        
        if(sum % 4)
            return false;
        
        int t=sum/4;
        sort(matchsticks.begin(), matchsticks.end(), greater<int> ());
        return helper(matchsticks, 0, n, t);
    }
};