/*
NEWTON RAPHSON METHOD
First we take a initial guess of a number then we iterate the number with this operation many times to get a good convergence using the operation:
                                                  Xn = Xn-1 - f(Xn-1) / f'(Xn-1)
                                                                                  Xn - root of function

It is based on tangent line approximation
                                                    Y = f(Xn) + f′(Xn)*(X−Xn)
                                                            Y = 0
                          Xn+1 = Xn − f′(Xn) / f(Xn) -> Xn + 1 = Xn - (Xn2 - a) / 2Xn -> Xn + 1 = (Xn + a / Xn) / 2

                                      Log(√n) = Log(n)/2 and [Log(n) of base 10 ] = no.of digits-1 
Start guess with 10^(t) where t = ((digits of n + 1) / 2) - 1
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

double squareRoot(int n, double guess) {
    for (int i=0; i<10; i++) 
        guess = (guess + (n / guess)) / 2;
    return guess;
}

void solve() {
    int n;
    cin >> n;
    int digits = log10(n);
    double guess = pow(10, digits / 2);
    cout << setprecision(7) << squareRoot(n, guess) << endl;
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
