class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(st.empty())
                st.push(s[i]);
            else if(s[i]=='*')
                st.pop();
            else
                st.push(s[i]);
        }
        s = "";
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};