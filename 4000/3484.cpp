// 3484. Design Spreadsheet
class Spreadsheet {
public:
    Spreadsheet(int rows) {
        sheet.reserve(rows);
    }
    
    void setCell(string cell, int value) {
        sheet[cell] = value;
    }
    
    void resetCell(string cell) {
        sheet[cell] = 0;
    }
    
    int getValue(string f) {
        for (int i=1; i<f.size(); i++) {
            if (f[i] == '+') {
                string s1 = f.substr(1, i-1);
                string s2 = f.substr(i+1);
                int v1 = isalpha(s1[0]) ? sheet[s1] : stoi(s1);
                int v2 = isalpha(s2[0]) ? sheet[s2] : stoi(s2);
                return v1 + v2;
            }
        }
        return 0;
    }

private:
    unordered_map<string, int> sheet;
};
