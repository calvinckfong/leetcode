// 2491. Divide Players Into Teams of Equal Skill
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        if (n==2) return skill[0]*skill[1];

        int totalSkill = accumulate(skill.begin(), skill.end(), 0);
        if (totalSkill % (n/2)) return -1;
        int avg_skill = totalSkill * 2 / n;

        sort(skill.begin(), skill.end());
        long long result = 0;
        for (int i=0; i<n/2; i++)
        {
            if (skill[i] + skill[n-1-i] != avg_skill) return -1;
            result += skill[i] * skill[n-1-i];
        }

        return result;
    }
};
