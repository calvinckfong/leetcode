// 394. Decode String
class Solution {
public:
    
    string decodeString(string s) {
        string result;
        stack<string> sstack;
        stack<int> nstack;
        int num = 0;
        for (int i=0; i<s.length(); i++)
        {
            // keep track k
            if (isdigit(s[i]))
            {
                num = 10*num + s[i] - '0';
            }
            // keep track encoded_string
            if (isalpha(s[i]))
            {
                result += s[i];
            }
        
            if (s[i] == '[')
            {
                sstack.push(result);
                nstack.push(num);
                result="";
                num=0;
            }
            else if (s[i] == ']')
            {
                string tmp;
                for (int j=0; j<nstack.top(); j++)
                    tmp += result;
                result = sstack.top() + tmp;
                nstack.pop();
                sstack.pop();
            }
        }
        return result;
    }
};
