int mod_exp(int base, int exp, int m) {
    int res = 1;
    base %= m;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % m;
        base = (base * base) % m;
        exp >>= 1;
    }
    return res;
}

int mod_inv(int base, int m) {return mod_exp(base, m - 2, m);}

int mod_add(int a, int b, int m) {return (((a % m + b % m) % m) + m) % m;}
int mod_mul(int a, int b, int m) {return (1LL * (a % m) * (b % m)) % m;}
int mod_sub(int a, int b, int m) {return (((a % m - b % m) % m) + m) % m;}
int mod_div(int a, int b, int m) {return mod_mul(a, mod_inv(b, m), m);}

struct Hashing {
    string s;
    int n;
    int primes;
    vector<int> hashPrimes = {1000000009, 100000007};
    const int base = 31;
    vector<vector<int>> hashValues;
    vector<vector<int>> powerOfBase;
    vector<vector<int>> inversePowerOfBase;
    Hashing(string a) {
        s = a;
        n = s.length();
        primes = hashPrimes.size();
        hashValues.resize(primes, vector<int>(n));
        powerOfBase.resize(primes, vector<int>(n + 1));
        inversePowerOfBase.resize(primes, vector<int>(n + 1));
        for (int i = 0; i < primes; i++) {
            int mod = hashPrimes[i];
            powerOfBase[i][0] = 1;
            for (int j = 1; j <= n; j++) 
                powerOfBase[i][j] = mod_mul(powerOfBase[i][j - 1], base, mod);
            inversePowerOfBase[i][n] = mod_inv(powerOfBase[i][n], mod);
            for (int j = n - 1; j >= 0; j--) 
                inversePowerOfBase[i][j] = mod_mul(inversePowerOfBase[i][j + 1], base, mod);
            for (int j = 0; j < n; j++) {
                int curr = mod_mul(s[j] - 'a' + 1, powerOfBase[i][j], mod);
                hashValues[i][j] = (curr + (j > 0 ? hashValues[i][j - 1] : 0)) % mod;
            }
        }
    }
    vector<int> substringHash(int l, int r) {
        vector<int> hash(primes);
        for (int i = 0; i < primes; i++) {
            int mod = hashPrimes[i];
            int val1 = hashValues[i][r];
            int val2 = l > 0 ? hashValues[i][l - 1] : 0;
            int diff = mod_sub(val1, val2, mod);
            hash[i] = mod_mul(diff, inversePowerOfBase[i][l], mod);
        }
        return hash;
    }
};
