class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        int repsum=accumulate(arr.begin(),arr.end(),0);
        set<int>s;
        for(auto &i:arr){
            s.insert(i);
        }
        int sum=accumulate(s.begin(),s.end(),0);
        int dup=repsum-sum,n=arr.size()+1;
        int miss=n*(n-1)/2-sum;
        return {dup,miss};
    }
};