class Solution {
public:
    string convert(string s, int numRows) {
        string ans[numRows],fin;
        if(numRows==1)
            return s;
        long long n= s.size(),rows=0;
        int m=0;
        for(long long i=0;i<n;i++){
            ans[rows].push_back(s[i]);
            if(rows==numRows-1)
                m=1;
            if(rows==0)
                m=0;
            (m==0)?rows++:rows--;
        }
        for(long long i=0;i<numRows;i++){
            fin=fin+ans[i];
        }
        return fin;
    }
};