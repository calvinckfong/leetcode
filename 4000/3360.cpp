// 3360. Stone Removal Game
class Solution {
public:
    bool canAliceWin(int n) {
        int next = 10;
        while (n>=next) {
            n -= next;
            next--;
            if (n<next) return true;
            n -= next;
            next--;
        }
        return false;
    }
};
