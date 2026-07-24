class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        int n = pat.size(), m = txt.size();
        string s = pat + "#" + txt;
        int N = s.size();
        vector <int> lps(N, 0);
        for (int i=1; i<N; i++) {
            int prev = lps[i-1];
            while (prev > 0 && s[i] != s[prev]) {
                prev = lps[prev-1];
            }
            lps[i] = prev + (s[i] == s[prev]);
        }
        vector <int> ans;
        for (int i=n+1; i<N; i++) {
            if (lps[i] == n) {
                ans.push_back(i-2*n);
            }
        }
        return ans;
    }
};
