class CustomStack {
public:
    vector<int> v;
    int sz = 0;
    int capacity;
    CustomStack(int maxSize) {
        v.assign(maxSize,-1);
        capacity = maxSize;
    }
    
    void push(int x) {
        if(sz >= capacity)
            return;
        v[sz] = x;
        sz++;
    }
    
    int pop() {
        int tmp;
        if(sz==0)
            return -1;
        else{
            tmp = v[sz-1];
            v[sz-1]=-1;
            sz--;
        }
        return tmp;
    }
    
    void increment(int k, int val) {
        if(k>=sz){
            for(int i=0;i<sz;i++)
                v[i]+=val;
        }
        else{
            for(int i=0;i<k;i++){
                v[i]+=val;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */