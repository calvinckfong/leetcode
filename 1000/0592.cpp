// 592. Fraction Addition and Subtraction
class Fraction {
public:
    Fraction() { A=0; B=1; }
    Fraction(int a, int b) { A=a; B=b; }
    string str() { return to_string(A) + "/" + to_string(B); }
    void add(int a, int b) {
        A = A*b + B*a;
        B = b*B;
        int f = abs(__gcd(A, B));
        A /= f;
        B /= f;
    }

private:
    int A, B;
};

class Solution {
public:
    string fractionAddition(string expression) {
        stringstream ss(expression);
        int a, b;
        char c;
        Fraction result;
        while (ss >> a >> c >> b) {
            //printf("%d %d\n", a, b);
            result.add(a, b);
        }
        return result.str();
    }
};
