// 1154. Day of the Year
class Solution {
public:
    bool isLeapYear(int year)
    {
        return (year%400==0 || (year%4==0 && year%100!=0));
    }
    int dayOfYear(string date) {
        const int days[12] = {31, 28, 31, 30, 31, 30,
                        31, 31, 30, 31, 30, 31};
        int yy, mm, dd;
        sscanf(date.c_str(), "%d-%d-%d", &yy, &mm, &dd);
        int result = dd;
        for (int i=0; i<mm-1; i++)
            result += days[i];
        if (mm>2 && isLeapYear(yy)) result++;

        return result;
    }
};
