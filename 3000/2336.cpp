// 2336. Smallest Number in Infinite Set
class SmallestInfiniteSet {
public:
    set<int> nums;
    SmallestInfiniteSet() {
        for(int i=1; i<=1000; i++)
            nums.insert(i);
    }
    
    int popSmallest() {
        int ret = *nums.begin();
        nums.erase(nums.begin());
        return ret;
    }
    
    void addBack(int num) {
        nums.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
