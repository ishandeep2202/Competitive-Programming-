/*
https://cses.fi/problemset/result/13215528/
Sliding Window Cost

Here to minimize cost we can get every element of subarray to the median of that subarray.
*/ 

#include <bits/stdc++.h>
 
#define int long long
#define endl '\n'
using namespace std;
 
void debugMode() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
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
 
    multiset <int> left, right;
    int leftSum = 0, rightSum = 0;
    auto balance = [&]() {
        if (left.size() > right.size() + 1) {
            rightSum += *left.rbegin();
            leftSum -= *left.rbegin();
            right.insert(*left.rbegin());
            left.erase(prev(left.end()));
        }
        if (right.size() > left.size()) {
            left.insert(*right.begin());
            leftSum += *right.begin();      
            rightSum -= *right.begin();
            right.erase(right.begin());
        }
    };
 
    for (int i=0; i<n; i++) {
        if (left.empty() || a[i] <= *left.rbegin()) {
            left.insert(a[i]);
            leftSum += a[i];
        }
        else {
            right.insert(a[i]);
            rightSum += a[i];
        }
        balance();
        
        if (i >= k) {
            if (a[i-k] <= *left.rbegin()) {
                left.erase(left.find(a[i-k]));
                leftSum -= a[i-k];
            }
            else {
                right.erase(right.find(a[i-k]));
                rightSum -= a[i-k];
            }
            balance();
        }
        
        if (i >= k-1) {
            int ans, median;
            if (k % 2) 
                median = *left.rbegin();
            else median = (*left.rbegin() + *right.begin()) / 2;
            ans = left.size() * median - leftSum + rightSum - right.size() * median;
            cout << ans << " ";
        }
    }   
  
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
