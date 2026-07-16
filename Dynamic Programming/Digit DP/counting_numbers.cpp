#include <bits/stdc++.h>

int main() {
    int64_t a, b;
    std::cin >> a >> b;

    std::string A = (a > 0 ? std::to_string(a-1) : "0");
    std::string B = std::to_string(b);

    int64_t dp[20][2][11][2];

    auto fn = [&](std::string& N, int ind, bool tight, int prev, bool zeros, auto&& fn) -> int64_t {
        if (ind == static_cast <int> (N.length())) { return 1; }
        if (dp[ind][tight][prev][zeros] != -1) { return dp[ind][tight][prev][zeros]; }
        int64_t res = 0;
        int LB = 0, UB = (tight ? N[ind]-'0' : 9);
        for (int d = LB; d <= UB; d++) {
            if (d == prev && !zeros) { continue; }
            res += fn(N, ind+1, tight && d == UB, d, zeros && !d, fn);
        }
        return dp[ind][tight][prev][zeros] = res;
    };
    
    memset(dp, -1, sizeof(dp));
    int64_t L = fn(A, 0, true, 10, true, fn);
    
    memset(dp, -1, sizeof(dp));
    int64_t R = fn(B, 0, true, 10, true, fn);

    std::cout << R - L + (a == 0) << '\n';
}
