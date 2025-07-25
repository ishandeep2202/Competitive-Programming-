const int MOD = 1e9 + 7;  

int mod_exp(int base, int exp, int m = MOD) {
    int res = 1;
    base %= m;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % m;
        base = (base * base) % m;
        exp >>= 1;
    }
    return res;
}

int mod_inv(int base, int m = MOD) {return mod_exp(base, m - 2, m);}

int mod_add(int a, int b, int m = MOD) {return (((a % m + b % m) % m) + m) % m;}
int mod_mul(int a, int b, int m = MOD) {return (1LL * (a % m) * (b % m)) % m;}
int mod_sub(int a, int b, int m = MOD) {return (((a % m - b % m) % m) + m) % m;}
int mod_div(int a, int b, int m = MOD) {return mod_mul(a, mod_inv(b, m), m);}
