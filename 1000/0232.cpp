// 232. Implement Queue using Stacks
class MyQueue {
public:
    stack<int> pri, sec;
    MyQueue() {
        
    }
    
    void push(int x) {
        pri.push(x);
    }
    
    int pop() {
        while (!pri.empty()) {
            sec.push(pri.top());
            pri.pop();
        }
        int result = sec.top();
        sec.pop();
        while (!sec.empty()) {
            pri.push(sec.top());
            sec.pop();
        }
        return result;
    }
    
    int peek() {
        while (!pri.empty()) {
            sec.push(pri.top());
            pri.pop();
        }
        int result = sec.top();
        while (!sec.empty()) {
            pri.push(sec.top());
            sec.pop();
        } 
        return result;    
    }
    
    bool empty() {
        return pri.empty();
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
