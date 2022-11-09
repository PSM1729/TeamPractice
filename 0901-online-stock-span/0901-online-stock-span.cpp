class StockSpanner {
public:
    stack<vector<int>> st; //{price,span}
    StockSpanner() {
    }
    
    int next(int price) {
        int span=1;
        while(!st.empty() && st.top()[0]<=price){
            span+=st.top()[1];
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */