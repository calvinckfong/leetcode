// 2349. Design a Number Container System
class NumberContainers {
public:
    void change(int index, int number) {
        idxToNum[index] = number;
        numToIdx[number].push(index);
    }

    int find(int number) {
        if (numToIdx.find(number) == numToIdx.end()) return -1;

        auto& minHeap = numToIdx[number];
        while (!minHeap.empty()) {
            int result = minHeap.top();
            if (idxToNum[result] == number) return result;
            minHeap.pop();
        }
        return -1;
    }

private:
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> numToIdx;
    unordered_map<int, int> idxToNum;
};
