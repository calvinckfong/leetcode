// 2073. Time Needed to Buy Tickets
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int result=0, th=tickets[k]-1;

        // the first few passes
        for (int i=0; i<tickets.size(); i++)
            result += min(th, tickets[i]);

        // the last pass
        for (int i=0; i<=k; i++)
            result += (tickets[i]>th);
        
        return result;
    }
};
