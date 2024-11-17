// 
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        // At most 8 LED is on
        if (turnedOn>8) return result;

        buildMMStrings();

        // HH at most 3 LED
        // MM at most 5 LED
        for (int HH=0; HH<=min(3, turnedOn); HH++) {
            int MM = turnedOn-HH;
            if (MM>5) continue;
            vector<string> HHstr = HHstrings[HH];
            vector<string> MMstr = MMstrings[MM];

            for (auto h: HHstr) {
                for (auto m:MMstr) {
                    result.push_back(h+":"+m);
                }
            }
        }
        return result;
    }

private:
    vector<vector<string>> HHstrings = {
        {"0"},
        {"1", "2", "4", "8"},
        {"3", "5", "6", "9", "10"},
        {"7", "11"}
    };

    vector<vector<string>> MMstrings = vector<vector<string>>(6);
    
    void buildMMStrings() {
        MMstrings[0].push_back("00");
        for (int i=1; i<10; i++) {
            int cnt = 0;
            int mm = i;
            while (mm) {
                cnt += (mm&1);
                mm>>=1;
            }
            MMstrings[cnt].push_back("0" + to_string(i));
        }
        for (int i=10; i<60; i++) {
            int cnt = 0;
            int mm = i;
            while (mm) {
                cnt += (mm&1);
                mm>>=1;
            }
            MMstrings[cnt].push_back(to_string(i));
        }
    }
};
