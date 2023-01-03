class Solution {
public:
    set<int> sl;
    void primeFactors(int n) { 
        while(n%2==0) { 
            sl.insert(2);
            n = n/2; 
        } 

        for (int i = 3; i <= sqrt(n); i = i+2) { 
            while(n%i==0) { 
                sl.insert(i);
                n = n/i; 
            } 
        } 
        if (n>2) 
            sl.insert(n); 
    } 
    int distinctPrimeFactors(vector<int>& nums) {
        for(auto it: nums){
            primeFactors(it);
        }
        return sl.size();
    }
};