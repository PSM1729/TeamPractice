class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int d[text1.length()+1][text2.length()+1];
        d[0][0]=0;
        for(int i=1;i<=text1.length();i++)
            d[i][0]= 0;
        for(int j=1;j<=text2.length();j++)
            d[0][j]= 0;
        for(int i=1;i<=text1.length();i++)
        {
            for(int j=1;j<=text2.length();j++)
            {
                if(text1[i-1]==text2[j-1])
                    d[i][j]= d[i-1][j-1] + 1;
                else
                    d[i][j]= max(d[i-1][j],d[i][j-1]);
            }
        }
        return d[text1.length()][text2.length()];
    }
};