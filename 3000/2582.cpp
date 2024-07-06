// 2582. Pass the Pillow
class Solution {
public:
    // Suppose n = 4
    // t      = 1 2 3 4 5 6 7 8 9 10 11
    // output = 2 3 4 3 2 1 2 3 4  3. 2
    // period is 6 = 2*(n-1)

    // making t is zero-index:
    // (t-1)             = 0 1 2 3 4 5 6 7 8 9 10 11 12
    // (t-1)%period      = 0 1 2 3 4 5 0 1 2 3  4  5  0
    // comparing with the output
    // first half period = 2 3 4       2 3 4.         2
    // second half       =       3 2 1       3. 2. 1
    // Hence, we can formulate as:
    int passThePillow(int n, int time) {
        int period = 2*(n-1);
        time = (time-1) % period;
        return (time<n-1)?(time+2):(period-time);
    }
};
