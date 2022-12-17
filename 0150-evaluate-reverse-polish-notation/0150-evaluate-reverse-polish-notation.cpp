class Solution {
public:

    int evalRPN(vector<string>& tokens) {
        stack<long long int> st;
        for(int i = 0; i < tokens.size(); ++i){
            string p = tokens[i];
            if(p != "+" && p != "-" && p != "/" && p != "*"){
                long long int ff = stoi(tokens[i]);
                st.push(ff);
            }
            else{
                long long int a = st.top();st.pop();
                long long int b = st.top();st.pop();
                long long int res;
                if(p == "+"){
                    res = b+a;
                }
                else if(p == "-"){
                    res = b-a;
                }
                else if(p == "*"){
                    res = b*a;
                }
                else{
                    res = b/a;
                }
                st.push(res);
            }
        }
        return st.top();
    }
};