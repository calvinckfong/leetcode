// 641. Design Circular Deque
class MyCircularDeque {
private:
    int capacity, size;
    int front, back;
    vector<int> elements;

public:
    MyCircularDeque(int k) : 
        capacity(k), size(0), front(k-1), back(0)
    {
        elements = vector<int>(k);
    }
    
    bool insertFront(int value) {
        if (size < capacity) {
            size ++;
            front = (front+1) % capacity;
            elements[front] = value;
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if (size < capacity) {
            size ++;
            back = (back + capacity - 1) % capacity;
            elements[back] = value;
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if (size > 0) {
            size --;
            front = (front + capacity - 1) % capacity;
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if (size > 0) {
            size --;
            back = (back + 1) % capacity;
            return true;
        }
        return false;
    }
    
    int getFront() {
        return (size > 0)?elements[front]:-1;
    }
    
    int getRear() {
        return (size > 0)?elements[back]:-1;
    }
    
    bool isEmpty() {
        return (size == 0);
    }
    
    bool isFull() {
        return (size == capacity);
    }
};
