class FenwikTree {
    int n;
    vector <int> bit;
public:
    FenwikTree(vector <int> A) {
        n = A.size();
        bit.resize(n+1, 0);
        for (int i=0; i<n; i++) {
            update(i+1, A[i]);
        }
    }
    void update(int ind, int val) {
        while (ind <= n) {
            bit[ind] = max(bit[ind], val);
            ind += (ind & -ind);
        }
    }
    int query(int ind) {
        int ans = 0;
        while (ind > 0) {
            ans = max(ans, bit[ind]);
            ind -= (ind & -ind);
        }
        return ans;
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int n = max(50000, (int) (3 * queries.size()));
        vector <int> line(n+5, 0);
        line[0] = 1;
        line[n+1] = 1;
        set <int> st;
        st.insert(0);
        st.insert(n+1);
        for (auto& q: queries) {
            if (q[0] == 1) {
                int x = q[1];
                line[x] = 1;
                st.insert(x);
            }
        }
        int pv = 0;
        for (int i=1; i<=n+1; i++) {
            if (!line[i]) {
                continue;
            }
            line[i] = i - pv;
            pv = i;
        }
        vector <bool> ans;
        FenwikTree ft{line};
        reverse(queries.begin(), queries.end());
        for (auto& q: queries) {
            if (q[0] == 1) {
                int x = q[1];
                auto it = st.find(x);
                ft.update(*next(it)+1, (*next(it)) - (*prev(it)));
                st.erase(it);
            }
            else {
                int x = q[1], s = q[2];
                auto it = st.upper_bound(x);
                it = prev(it);
                if (s <= x - *it || s <= ft.query(*it+1)) {
                    ans.push_back(true);
                }
                else {
                    ans.push_back(false);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
