// 649. Dota2 Senate
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rq, dq;

        // setup the 2 queues from senate
        int i;
        for (i=0; i<senate.size(); i++)
        {
            if (senate[i]=='R')
                rq.push(i);
            else
                dq.push(i);
        }

        // Start voting
        while (!rq.empty() && !dq.empty())
        {
            if (rq.front() < dq.front())
            {
                // pop dq an requeue rq
                dq.pop();
                rq.pop();
                rq.push(i++);
            }
            else
            {
                // pop rq an requeue dq
                rq.pop();
                dq.pop();
                dq.push(i++);
            }
        }

        return (rq.empty())?"Dire":"Radiant";
    }
};
