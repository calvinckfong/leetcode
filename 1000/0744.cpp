// 744. Find Smallest Letter Greater Than Target
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ret = 'z'+1;
        for (char& c: letters) {
            if (c > target)
                ret = min(ret, c);
        }
        return (ret<='z')?ret:letters[0];
    }
};
