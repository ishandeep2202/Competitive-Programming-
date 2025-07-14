#include <bits/stdc++.h>

#define int long long
#define endl '\n'
using namespace std;

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
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];
  
    multiset <int> low, high;
    auto balance = [&]() {
        if (low.size() > high.size() + 1) {
            high.insert(*low.rbegin());
            low.erase(prev(low.end()));
        }
        if (high.size() > low.size()) {
            low.insert(*high.begin());
            high.erase(high.begin());
        }
    };
  
    vector <double> ans;
    for (int i=0; i<n; i++) {
        if (low.empty() || a[i] <= *low.rbegin())
            low.insert(a[i]);
        else high.insert(a[i]);
        balance();
      
        if (i >= k) {
            int out = a[i-k];
            if (out <= *low.rbegin()) 
                low.erase(low.find(out));
            else high.erase(high.find(out));
            balance();
        }
      
        if (i >= k-1) {
            if (k % 2 == 1) 
                ans.push_back(*low.rbegin());
            else {
                double push =((double)*low.rbegin() + (double)*high.begin()) / 2.0;
                ans.push_back(push);
            }
        }
    }
  
    for (auto &i: ans) 
        cout << i << " ";
    cout << endl;
}

int32_t main() {
    debugMode();
    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }   
    return 0;
}
