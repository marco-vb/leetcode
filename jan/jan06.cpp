class Solution {
public:
    struct job {
        int st, en, pr;
        
        bool operator<(job& o) {
            return st < o.st;
        }
    };
    
    int best(int i, int n, vector<job>& jobs, vector<int>& start, vector<int>& mem) {
        if (i == n) return 0;
        if (mem[i] > -1) return mem[i];
        
        auto& job = jobs[i];
        int idx = lower_bound(start.begin(), start.end(), job.en) - start.begin();
        int use = best(idx, n, jobs, start, mem);
        int nuse = best(i+1, n, jobs, start, mem);
        
        return mem[i] = max(job.pr + use, nuse);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<job> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        
        sort(jobs.begin(), jobs.end());
        sort(startTime.begin(), startTime.end());
        vector<int> mem(n, -1);
        
        return best(0, n, jobs, startTime, mem);
    }
};
