class MyQueue {
public:
    stack<int> st;
    stack<int> st1;
    MyQueue() {
        
    }
    
    void push(int x) {
        int n = st.size();
        while(!st.empty()){
            st1.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!st1.empty()){
             st.push(st1.top());
            st1.pop();
        }
    }
    
    int pop() {
       int ans = st.top();
       st.pop();
       return ans; 
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
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