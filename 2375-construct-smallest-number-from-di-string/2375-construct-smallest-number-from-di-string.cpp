class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        string tmp = "";
        pattern+='I';
        for(int i=1;i<=n+1;i++){
            tmp+=to_string(i);
        }
        int i=0,j;
        while(i<=n){
            if(pattern[i]=='D'){
                j=i;
                while(pattern[i]!='I'){
                    i++;
                }
                //cout<<j<<i<<" ";
                reverse(tmp.begin()+j,tmp.begin()+i+1);
            }
            i++;
        }
        return tmp;
    }
};