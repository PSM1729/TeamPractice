class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        stack<char> st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && st.top()>num[i] && k>0){
                st.pop();
                k--;
            }
            if(st.empty() && num[i]=='0')
                continue;
            st.push(num[i]);
        }
        while(!st.empty() && k--){
            st.pop();
        }
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return (ans=="")?"0":ans;
    }
};