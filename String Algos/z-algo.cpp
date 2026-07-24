class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        int n = pat.size(), m = txt.size();
        string s = pat + "#" + txt;
        int N = s.size();
        vector <int> z(N, 0);
        int l = 0, r = 0;
        for (int i=1; i<N; i++) {
            if (i > r) {
                l = i;
                r = i;
                while (r < N && s[r-l] == s[r]) {
                    r++;
                }
                z[i] = r-l;
                r--;
            }
            else {
                int k = i-l;
                if (i+z[k] <= r) {
                    z[i] = z[k];
                }
                else {
                    l = i;
                    r++;
                    while (r < N && s[r-l] == s[r]) {
                        r++;
                    }
                    z[i] = r-l;
                    r--;
                }
            }
        }
        vector <int> ans;
        for (int i=n+1; i<N; i++) {
            if (z[i] == n) {
                ans.push_back(i-n-1);
            }
        }
        return ans;
    }
};
