class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        set<int> st;
        int ans =1;
        for(auto it : rolls){
            st.insert(it);
            if(st.size()==k){
                ans++;
                st.clear();
            }
        }
        return ans;
    }
};