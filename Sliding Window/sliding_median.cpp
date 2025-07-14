// PBDS - Policy based data structures

/*
https://cses.fi/problemset/task/1076
Sliding Window Median
*/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

#define int long long
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;

void debugMode() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

template <class T> 
using ordered_set = tree <
    T,
    null_type,
    less <T>,
    rb_tree_tag,
    tree_order_statistics_node_update
>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ordered_set<pair<int, int>> st;
    vector<int> ans;
    ans.reserve(n - k + 1);

    for (int i = 0; i < n; i++) {
        st.insert({a[i], i});
        if (i >= k)
            st.erase({a[i - k], i - k});

        if (i >= k - 1) {
            int mid = (k + 1)/2;
            auto it = st.find_by_order(mid-1);
            ans.push_back((*it).first);
        }
    }

    for (auto &i : ans)
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
