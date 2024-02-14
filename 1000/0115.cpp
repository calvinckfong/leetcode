// 155. Min Stack
class MinStack {
public:
    stack<int> m_stack; // keep minimum values
    stack<int> n_stack; // keep normal values
    
    MinStack() {
        
    }
    
    void push(int val) {
        n_stack.push(val);
        // keep in m_stack if m_stock is empty or it is smallest among values pushed
        if (m_stack.empty() || val<=getMin()) m_stack.push(val);
    }
    
    void pop() {
        if (n_stack.top() == getMin()) m_stack.pop();
        n_stack.pop();
    }
    
    int top() {
        // retrieve from n_stack 
        return n_stack.top();
    }
    
    int getMin() {
        // retrieve from m_stack
        return m_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
