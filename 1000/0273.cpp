// 273. Integer to English Words
class Solution {
public:
    string toWords(int num) {
        string strmap[] = {"", "One", "Two", "Three", "Four", 
                        "Five", "Six", "Seven", "Eight", "Nine",
                        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string strmap2[] = {"", "", "Twenty", "Thirty", "Forty",
                        "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string result;

        if (num>99)
        {
            result += strmap[num/100] + " Hundred";
            num%=100;
            if (num)
            result += " ";
        }
        if (num>19)
        {
            result += strmap2[num/10];
            if (num%10) result += " " + strmap[num%10];
        }
        else 
        {
            result += strmap[num];
        }

        return result;
    }

    string numberToWords(int num) {
        if (num==0) return "Zero";
        string result;
        string strmap[] = {"", " Thousand", " Million", " Billion"};
        int lvl = 0;
        while (num)
        {
            if (num%1000)
                result = toWords(num%1000) + strmap[lvl] + ((result.size()>0)?" ":"") + result;
            num /= 1000;
            lvl++;
        }
        return result;
    }
};
