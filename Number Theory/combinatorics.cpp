const int MOD = 1e9 + 7;  

int mod(int a, int m = MOD) {
    return ((a % m) + m) % m;  
}

template <class T>
class Math {
public:
    vector<T> fact, invfact;

    Math() {}

    Math(int n) {
        fact.resize(n);
        invfact.resize(n);
        fact[0] = invfact[0] = 1;
        for (int i = 1; i < n; i++) {
            fact[i] = mod(fact[i - 1] * i);
        }
        invfact[n - 1] = mod_inv(fact[n - 1]); 
        for (int i = n - 2; i >= 1; i--) {
            invfact[i] = mod(invfact[i + 1] * (i + 1));
        }
    }

    T mod_exp(T base, T exp, T m = MOD) {
        T result = 1;
        base = mod(base, m);
        while (exp > 0) {
            if (exp % 2 == 1)
                result = mod(result * base, m);
            base = mod(base * base, m);
            exp /= 2;
        }
        return result;
    }

    T mod_inv(T base, T m = MOD) {
        return mod_exp(base, m - 2, m); 
    }

    T nCr_mod(T n, T r) {
        if (r < 0 || r > n)
            return 0;
        T ans = fact[n];
        ans = mod(ans * invfact[n - r]);
        ans = mod(ans * invfact[r]);
        return ans;
    }
};
