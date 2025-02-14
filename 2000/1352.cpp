// 1352. Product of the Last K Numbers
class ProductOfNumbers {
public:
    ProductOfNumbers() {
        prod.push_back(1);
        size = 0;
    }
    
    void add(int num) {
        if (num == 0) {
            prod = {1};
            size = 0;
        } else {
            prod.push_back(prod[size] * num);
            size++;
        }
    }
    
    int getProduct(int k) {
        if (k>size) return 0;
        return prod[size] / prod[size-k];
    }

private:
    vector<int> prod;
    int size = 0;
};
