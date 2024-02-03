// 901. Online Stock Span
class StockSpanner {
public:
    typedef struct Span {
        int price;
        int span;
    } Span;
    vector<Span> spans;

    StockSpanner() {
    }
    
    int next(int price) {
        int n=spans.size(), i=n-1;
        while (i>=0 && spans[i].price<=price)
        {
            i-=spans[i].span;
        }
        spans.push_back({price, n-i});
        return n-i;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
