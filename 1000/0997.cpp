// 997. Find the Town Judge
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // handle exception case 
        if (n==1 && trust.size()==0) return 1;

        vector<int> freq(n+1, 0);
        for (int i=0; i<trust.size(); i++)
        {
            freq[trust[i][0]]--; 
            freq[trust[i][1]]++;
        }

        for (int i=1; i<n+1; i++)
            if (freq[i] == n-1) return i;
        
        return -1;
    }
};
