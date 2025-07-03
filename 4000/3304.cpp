// 3304. Find the K-th Character in String Game I
class Solution {
public:
    char kthCharacter(int k) {
        k--;
        char res = 'a';
        while (k) {
            k &= k-1;
            res++;
        }
        return res;
    }
};
