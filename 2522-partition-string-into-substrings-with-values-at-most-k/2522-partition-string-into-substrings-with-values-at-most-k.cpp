class Solution {
public:
    int minimumPartition(string s, int k) {
        int n=s.length();
        if(k>0 && k<=9){
            for(auto it: s)
                if(int(it) -'0'>k)
                    return -1;
        }
        int mp = 0 ,i = 0;
        long long tmp = 0;
        while(i<n){
            tmp=tmp*10 + (int(s[i])-'0');
            if(tmp > k){
                mp++;
                tmp=int(s[i])-'0';
                cout<<tmp<<"*";
            }
            i++;
            cout<<tmp<<" ";
        }
        return mp+1;
    }
};