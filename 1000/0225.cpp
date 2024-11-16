// 225. Implement Stack using Queues
class MyStack {
public:
    MyStack() {
        q.clear();
    }
    
    void push(int x) {
        q.push_back(x);
    }
    
    int pop() {
        int result = q.back();
        q.pop_back();
        return result;
    }
    
    int top() {
        int result = q.back();
        return result;
    }
    
    bool empty() {
        return q.empty();
    }

private:
    deque<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
