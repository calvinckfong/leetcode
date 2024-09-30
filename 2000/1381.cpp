// 1381. Design a Stack With Increment Operation
class CustomStack {
private:
    int top, size;
    vector<int> data;

public:
    CustomStack(int maxSize) : top(0), size(maxSize) {
        data = vector<int>(maxSize);
    }
    
    void push(int x) {
        if (top < size) data[top++] = x;
    }
    
    int pop() {
        return (top > 0) ? data[--top] : -1;
    }
    
    void increment(int k, int val) {
        for (int i=0; i<min(k, top); i++)
            data[i] += val;
    }
};
