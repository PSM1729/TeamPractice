class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size(), ans = 0;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y')
                ans++;
        }
        int ct = ans, mx = -1;
        for(int i=0;i<n;i++){
            if(customers[i]=='Y')
                ans--;
            else if(customers[i]=='N')
                ans++;
            
            if(ct>ans){
                ct = ans;
                mx = i+1;
            }
        }
        return (mx==-1)? 0: mx;
    }
};