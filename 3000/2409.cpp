// 2409. Count Days Spent Together
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
    
        for (int i=1; i<=12; i++) {
            prfSum[i] = prfSum[i-1] + dom[i-1];
        }
        
        int arriveA = dayOfYear(arriveAlice);
        int leaveA = dayOfYear(leaveAlice);
        int arriveB = dayOfYear(arriveBob);
        int leaveB = dayOfYear(leaveBob);
        return max(0, min(leaveA, leaveB) - max(arriveA, arriveB) + 1);
    }
    
private:
    int dom[12] = {31, 28, 31, 30, 31, 30,
                   31, 31, 30, 31, 30 , 31};
    int prfSum[13] = {0};

    int dayOfYear(const string& date) {
        int m = stoi(date.substr(0, 2));
        int d = stoi(date.substr(3));
        return prfSum[m-1] + d;
    }
};
