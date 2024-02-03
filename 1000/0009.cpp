// 9. Palindrome Number
class Solution {
public:
    bool isPalindrome(int x) {
        long reverse=0, xx=x;
        while (xx>0)
        {
            reverse = reverse*10 + (xx%10);
            xx/=10;
        }

        return (reverse==x);
    }
};
