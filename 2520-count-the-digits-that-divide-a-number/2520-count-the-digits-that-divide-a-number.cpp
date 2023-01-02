class Solution {
public:
    int countDigits(int num) {
        vector<int> lp;
        int tmp = num;
        while(tmp>0){
            lp.push_back(tmp%10);
            tmp=tmp/10;
        }
        tmp = 0;
        for(auto it: lp){
            if(num%it==0)
                tmp++;
        }
        return tmp;
    }
};