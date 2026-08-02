class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue <pair <int, int>> pq1, pq2;
        vector <int> cnt(26, 0);
        for (auto &c: tasks) {
            cnt[c-'A']++;
        }
        for (int i=0; i<26; i++) {
            if (cnt[i]) {
                pq1.push({cnt[i], i});
            }
        }
        int ans = 0;
        auto fn = [&](priority_queue <pair <int, int>> &pq1, priority_queue <pair <int, int>> &pq2) -> int {
            int c = 0;
            while (c <= n && !pq1.empty()) {
                auto curr = pq1.top();
                pq1.pop();
                curr.first--;
                if (curr.first) {
                    pq2.push(curr);
                }
                c++;
            }
            while (!pq1.empty()) {
                auto curr = pq1.top();
                pq1.pop();
                pq2.push(curr);
            }
            if (pq1.empty() && pq2.empty()) {
                return c;
            }
            else {
                return n+1;
            }
        };
        while (!pq1.empty() || !pq2.empty()) {
            if (pq1.empty()) {
                ans += fn(pq2, pq1);
            }
            else {
                ans += fn(pq1, pq2);
            }
        }
        return ans;
    }
};
