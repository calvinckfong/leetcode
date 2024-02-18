// 564. Find the Closest Palindrome
class Solution {
public:
    bool isPow10(string n)
    {
        n[0] -= 1;
        return (stol(n)==0);
    }
    bool isPalindromic(string n)
    {
        int l=0, r=n.size()-1;
        while (l<r)
        {
            if (n[l]!=n[r]) return false;
            l++; r--;
        }
        return true;
    }
    bool isAll1(string n)
    {
        for (int i=0; i<n.size(); i++)
            if (n[i]!='1') return false;
        return true;
    }
    bool isAll9(string n)
    {
        for (int i=0; i<n.size(); i++)
            if (n[i]!='9') return false;
        return true;
    }
    string nearestPalindromic(string n) {
        long val = stol(n);
        if (isPow10(n)) return to_string(val-1);
        else if (isAll9(n)) return (val>10)?to_string(val+2):to_string(val-1);
        else if (val>2 && isPow10(to_string(val-1))) return to_string(val-2);
        else if (val<9) return to_string(val-1);
        else if (isPalindromic(n))
        {
            int len = n.size(), l = len/2;
            if (len%2) // odd length
            {
                if (n[l]!='0') { n[l]-=1; return n; }
                else { n[l]+=1; return n; }
            }
            else
            {
                if (n[l]!='0') 
                { 
                    if (val==11) return "9";
                    else { n[l]-=1; n[l-1]=n[l]; return n; }
                }
                else {
                    val -= pow(10, l-1);
                    return nearestPalindromic(to_string(val));
                }
            }
        }
        else 
        {
            int l=0, r=n.size()-1;
            while (l<r)
            {
                n[r] = n[l];
                string n2 = n; ++n2[r-1]; n2[r] = n2[l];
                string n3 = n; --n3[r-1]; n3[r] = n3[l];
                long val1 = abs(stol(n) - val);
                long val2 = abs(stol(n2) - val);
                long val3 = abs(stol(n3) - val);

                if (val3>0 && val3<=val1 && val3<=val2)
                    n = n3;
                else if (val2>0 && val2<val1 && val1<val3)
                    n = n2;
                
                l++; r--;
            }
            return n;
        }
    }
};
