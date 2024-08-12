// 703. Kth Largest Element in a Stream
class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        m_k = k;
        for (int i: nums) {
            add(i);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size()>m_k) {
            pq.pop();
        }
        return pq.top();
    }

private:
    int m_k;
    priority_queue<int, vector<int>, greater<int>> pq;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
