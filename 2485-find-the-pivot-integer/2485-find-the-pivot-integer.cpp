class Solution {
public:
    int pivotInteger(int n) {
        if(n==1)
            return 1;
        vector<int> sff(n+1,0), pff(n+1,0);
        for(int i=1;i<=n;i++)
            sff[i]=sff[i-1]+i;
        
        pff[n]=n;
        for(int i=n-1;i>=1;i--){
            pff[i]=pff[i+1]+i;
            if(pff[i]==sff[i])
                return i;
        }
        
        return -1;
    }
};