// 2300. Successful Pairs of Spells and Potions
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int spell_size = spells.size();
        int portion_size = potions.size();
        vector<int> result(spell_size);
        sort(potions.begin(), potions.end());
        
        for (int i=0; i<spell_size; i++)
        {
            int cnt = 0;
            long long spell = spells[i];
            int l=0, r=portion_size, m;
            while (l<r)
            {
                m = l + (r-l)/2;
                if ((long long)(potions[m])*spell>=success) r=m;
                else l=m+1;
            }
            result[i] = portion_size-l;
        }
        return result;
    }
};
