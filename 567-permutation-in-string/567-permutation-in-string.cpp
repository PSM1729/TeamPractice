class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length())
            return false;
        vector<int> ps1(256,0);
        for(int i=0;i<s1.size();i++){
            ps1[s1[i]]++;
        }
        int i=0,j=s1.length()-1;
        //cout<<i<<j<<" ";
        while(i<=s2.length()-s1.length()){
            
            vector<int> ps2(256,0);
            for(int k=i;k<=j;k++)
                ps2[s2[k]]++;
            
            if(ps1 == ps2)
                return true;
            j++;i++;
        }
        return false;
    }
};