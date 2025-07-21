/*
https://codeforces.com/group/fkQQ5I8JeS/contest/538618/problem/C
A Galactic Mission

For this problem define dp as time taken to move from i to i+1, i+2, i+3, ... , n
dp1 - when parity is even
dp2 - when parity is odd

if (s[i] == '1') {
  dp1[i] = dp2[i+1] + n - i;
  dp2[i] = dp2[i+1] + 2LL * (n - i);
}
dp1[i] = dp2[i+1] + n - i; 
If parity is even and changes to odd, which means that no change in parity before crosing the i'th index, after that parity changes due to the time taken at 1 of i'th index

dp2[i] = dp2[i+1] + 2LL * (n - i);
For even odd time taken before, the colour of light changes to red. Now take 2 sec at the index and again land at odd parity


else {
  dp1[i] = dp1[i+1] + 2LL * (n - i);
  dp2[i] = dp1[i+1] + n - i;
} 
dp1[i] = dp1[i+1] + 2LL * (n - i);
For even parity, take even time before, colour remains red, so take 2 sec to cross the signal, parity remains same

dp2[i] = dp1[i+1] + n - i;
For odd parity take odd time before colour changes to green, take 1 sec to cross the signal, parity changes to even

*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define INF (LLONG_MAX >> 1)

void debugMode() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

void solve() {
    string s;
    cin >> s;
    // 0 - initially red
    // 1 - initially green
    int n = s.size();
    vector <int> dp1(n+1, 0), dp2(n+1, 0);
    // dp1 = even
    // dp2 = odd
    int ans = 0;
    for (int i=n-1; i>=0; i--) {
        if (s[i] == '1') {
            dp1[i] = dp2[i+1] + n - i;
            dp2[i] = dp2[i+1] + 2LL * (n - i);
        }
        else {
            dp1[i] = dp1[i+1] + 2LL * (n - i);
            dp2[i] = dp1[i+1] + n - i;
        } 
        ans += dp1[i];
    }
    cout << ans << endl;
}

int32_t main() {
    debugMode();
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
