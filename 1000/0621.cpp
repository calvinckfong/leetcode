// 621. Task Scheduler
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int cnt[26] = {0}, maxCnt=0, numMaxCnt=0;
        // Count the frequencies of the tasks
        for (int i=0; i<tasks.size(); i++)
            cnt[tasks[i]-'A']++;
        // find the max freq
        for (int i=0; i<26; i++)
            maxCnt = max(maxCnt, cnt[i]);
        // find the number of tasks have max freq
        for (int i=0; i<26; i++)
            if (cnt[i]==maxCnt) numMaxCnt++;

        return max((int)tasks.size(), (maxCnt-1)*(n+1) + numMaxCnt);
    }
};
