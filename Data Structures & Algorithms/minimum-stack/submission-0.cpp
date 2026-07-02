class MinStack {
    private:
    stack<int>st;
    stack<int>m_stack;
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if(!(m_stack.empty()))m_stack.push(min(val,m_stack.top()));
        else m_stack.push(val);
    }
    
    void pop() {
        st.pop();
        m_stack.pop();
    }
    
    int top() {
        return st.top();
        
    }
    
    int getMin() {
        return m_stack.top();
        
    }
};
