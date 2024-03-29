class MyQueue {
public:
    stack<int> st1, st2; //st2 ll behave as queue
    MyQueue() {
    }
    
    void push(int x) {
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        st1.push(x);
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
    }
    
    int pop() {
        int f = st2.top();
        st2.pop();
        return f;
    }
    
    int peek() {
        int fr = st2.top();
        return fr;
    }
    
    bool empty() {
        return st2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */