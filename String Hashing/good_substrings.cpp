/*
https://codeforces.com/contest/271/problem/D
Good Substrings

Number of distinct substrings which contains atmost k bad charecters
*/

#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

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

ull mod_exp(ull base, ull exp, ull m) {
    ull res = 1;
    base %= m;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % m;
        base = (base * base) % m;
        exp >>= 1;
    }
    return res;
}

ull mod_inv(ull base, ull m) {return mod_exp(base, m - 2, m);}

ull mod_add(ull a, ull b, ull m) {return (((a % m + b % m) % m) + m) % m;}
ull mod_mul(ull a, ull b, ull m) {return (1LL * (a % m) * (b % m)) % m;}
ull mod_sub(ull a, ull b, ull m) {return (a % m + m - b % m) % m;}
ull mod_div(ull a, ull b, ull m) {return mod_mul(a, mod_inv(b, m), m);}

struct Hashing {
    string s;
    ull n;
    ull primes;
    vector<ull> hashPrimes = {1000000009, 100000007};
    const ull base = 31;
    vector<vector<ull>> hashValues;
    vector<vector<ull>> powerOfBase;
    vector<vector<ull>> inversePowerOfBase;
    Hashing(string a) {
        s = a;
        n = s.length();
        primes = hashPrimes.size();
        hashValues.resize(primes, vector<ull>(n));
        powerOfBase.resize(primes, vector<ull>(n + 1));
        inversePowerOfBase.resize(primes, vector<ull>(n + 1));
        for (int i = 0; i < primes; i++) {
            ull mod = hashPrimes[i];
            powerOfBase[i][0] = 1;
            for (int j = 1; j <= n; j++) 
                powerOfBase[i][j] = mod_mul(powerOfBase[i][j - 1], base, mod);
            inversePowerOfBase[i][n] = mod_inv(powerOfBase[i][n], mod);
            for (int j = n - 1; j >= 0; j--) 
                inversePowerOfBase[i][j] = mod_mul(inversePowerOfBase[i][j + 1], base, mod);
            for (int j = 0; j < n; j++) {
                ull curr = mod_mul(s[j] - 'a' + 1, powerOfBase[i][j], mod);
                hashValues[i][j] = (curr + (j > 0 ? hashValues[i][j - 1] : 0)) % mod;
            }
        }
    }
    ull substringHash(ull l, ull r) {
        vector<ull> hash(primes);
        for (int i = 0; i < primes; i++) {
            ull mod = hashPrimes[i];
            ull val1 = hashValues[i][r];
            ull val2 = l > 0 ? hashValues[i][l - 1] : 0;
            ull diff = mod_sub(val1, val2, mod);
            hash[i] = mod_mul(diff, inversePowerOfBase[i][l], mod);
        }
        return hash[0] << 32 | hash[1];
    }
};

void solve() {
    string s, g;
    cin >> s >> g;
    ull k, n = s.size();
    cin >> k;
    Hashing hs = Hashing(s);
    unordered_set <ull> uni;
    vector <ull> bad;
    for (int i=0; i<26; i++) {
        if (g[i] == '0') {
            char ch = i + 'a';
            for (int j=0; j<n; j++) 
                if (s[j] == ch) 
                    bad.push_back(j);
        }
    }
    sort(bad.begin(), bad.end());
    vector <ull> preB(n+1, 0);
    ull curr = 0;
    for (int i=1; i<=n; i++) {
        if (curr < bad.size() && i-1 == bad[curr]) {
            preB[i] = preB[i-1] + 1;
            curr++;
        }
        else preB[i] = preB[i-1]; 
    } 
    for (int sb=1; sb<=n; sb++) {
        for (int i=0; i<=n-sb; i++) {
            ull start = i, end = i+sb-1;
            ull len = preB[end+1] - preB[start];
            if (len > k) continue;
            ull hash = hs.substringHash(start, end);
            uni.insert(hash);
        }
    }
    cout << uni.size() << endl;
}

int32_t main() {
    debugMode();
    ull tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
