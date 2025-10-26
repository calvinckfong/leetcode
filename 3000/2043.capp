// 2043. Simple Bank System
class Bank {
public:
    Bank(vector<long long>& balance) : accounts(balance) {
        
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1<=accounts.size() && account2<=accounts.size()) {
            if (accounts[account1-1] >= money) {
                accounts[account1-1] -= money;
                accounts[account2-1] += money;
                return true;
            }
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if (account > accounts.size()) return false;
        accounts[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account<=accounts.size()) {
            if (accounts[account-1] >= money) {
                accounts[account-1] -= money;
                return true;
            }
        }
        return false;
    }

private:
    vector<long long> accounts;
};
