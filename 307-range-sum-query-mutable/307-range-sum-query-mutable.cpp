class NumArray {
public:
    vector<int> st;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        st.resize(n * 2);
        for(int i = n * 2 - 1; i > 0; --i)
            st[i] = i > n - 1 ? nums[i - n] : st[i * 2] + st[i * 2 + 1];
    }
    
    void update(int i, int val) {
        for(st[i += n] = val; i > 1; i /= 2) 
            st[i / 2] = st[i] + st[i ^ 1];
    }
    
    int sumRange(int l, int r) {
        int sum = 0;
        for(l += n, r += n; l <= r; l /= 2, r /= 2)
            sum += (l % 2 ? st[l++] : 0) + (!(r % 2) ? st[r--] : 0);
        return sum;
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */