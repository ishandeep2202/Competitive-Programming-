#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    string S;
    for (auto& ch: s) {
        S += "#";
        S += ch;
    }
    S += "#";
    int N = S.size();
    vector <int> p(N, 0);

    int l = -1, r = 1;
    for (int i=0; i<N; i++) {
        int m = l + r - i;
        if (i < r && m >= 0 && m < N) {
            p[i] = min(r-i, p[m]);
        }
        while (i-p[i] >= 0 && i+p[i] < N && S[i-p[i]] == S[i+p[i]]) {
            p[i]++;
        }
        if (i+p[i] > r) {
            l = i-p[i];
            r = i+p[i];
        }
    }
    int pal = *max_element(p.begin(), p.end());
    vector <int> ind;
    for (int i=0; i<N; i++) {
        if (p[i] == pal) {
            if ((pal-1) % 2) {
                ind.push_back(i);
                int a = i-2, b = i+2;
                while (ind.size() != pal-1) {
                    ind.push_back(a);
                    ind.push_back(b);
                    a -= 2;
                    b += 2;
                }
            }
            else {
                int a = i-1, b = i+1;
                while (ind.size() != pal-1) {
                    ind.push_back(a);
                    ind.push_back(b);
                    a -= 2;
                    b += 2;
                }
            }
            break;
        }
    }
    sort(ind.begin(), ind.end());
    string ans;
    for (auto& i: ind) {
        ans += S[i];
    }
    cout << ans << '\n';
}
