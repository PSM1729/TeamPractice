class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string tmp="";
        int i=0, n=s.length();
        while(s[i]==' '){
            i++;
        }
        while(s[n-1]==' '){
            n--;
        }
        for(;i<n;){
            if(s[i]==' '){
                while(s[i]==' '){
                    i++;
                }
                st.push(tmp);
                st.push(" ");
                tmp="";
            }
            else
                tmp+=s[i++];
        }
        st.push(tmp);
        tmp="";
        while(!st.empty()){
            tmp+=st.top();
            st.pop();
        }
        return tmp;
    }
};