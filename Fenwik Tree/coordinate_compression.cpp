#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define INF (LLONG_MAX >> 1)

class FenwikTree {
    int N;
    vector <int> bit;
public:
    FenwikTree(int n) {
        N = n;
        bit.resize(n+1, 0);
    }
    void update(int ind, int val) {
        while (ind <= N) {
            bit[ind] += val;
            ind += (ind & -ind);
        }
    } 
    int query(int ind) {
        int res = 0;
        while (ind > 0) {
            res += bit[ind];
            ind -= (ind & -ind);
        }
        return res;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector <int> p(n), mp;
    for (int i=0; i<n; i++) {
        cin >> p[i];
        mp.push_back(p[i]);
    }
    vector <pair <char, pair <int, int>>> queries;
    for (int i=0; i<q; i++) {
        char type;
        cin >> type;
        if (type == '!') {
            int k, x;
            cin >> k >> x;
            mp.push_back(x);
            queries.push_back({type, {k, x}});
        } 
        else {
            int a, b;
            cin >> a >> b;
            queries.push_back({type, {a, b}});
        }
    }
    sort(mp.begin(), mp.end());
    vector <int> MP;
    for (int i=0; i<(int)mp.size(); ) {
        MP.push_back(mp[i]);
        int j = i+1;
        while (j<(int)mp.size() && mp[j] == mp[i]) {
            j++;
        }
        i = j;
    }

    FenwikTree ft(MP.size());
    for (int i=0; i<n; i++) {
        int ind = lower_bound(MP.begin(), MP.end(), p[i]) - MP.begin() + 1;
        ft.update(ind, 1);
    }
    
    for (int i=0; i<q; i++) {
        char type = queries[i].first;
        if (type == '!') {
            int k = queries[i].second.first, x = queries[i].second.second;
            int ind1 = lower_bound(MP.begin(), MP.end(), p[k-1]) - MP.begin() + 1;
            ft.update(ind1, -1);
            p[k-1] = x;
            int ind2 = lower_bound(MP.begin(), MP.end(), p[k-1]) - MP.begin() + 1;
            ft.update(ind2, 1);
        }
        else {
            int a = queries[i].second.first, b = queries[i].second.second;
            int ind1 = lower_bound(MP.begin(), MP.end(), a) - MP.begin() + 1;
            int ind2 = upper_bound(MP.begin(), MP.end(), b) - MP.begin();
            int val = ft.query(ind2) - ft.query(ind1-1);
            cout << val << endl;
        }
    }
}
