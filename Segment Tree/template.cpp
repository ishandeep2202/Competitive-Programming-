#include <bits/stdc++.h>
using namespace std;
#define int long long 

template <typename Node, typename Update>
struct SegTree {
    vector <Node> tree;
    vector <int> arr;
    int n, s;
    SegTree(int a_len, vector <int> &a) {
        arr = a;
        n = a_len;
        s = 1;
        while (s < 2*n)
            s = (s << 1LL);
        tree.resize(s);
        build(0, n-1, 0);
    }
    void build(int start, int end, int ind) {
        if (start == end) {
            tree[ind] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2*ind+1);
        build(mid+1, end, 2*ind+2);
        tree[ind].merge(tree[2*ind+1], tree[2*ind+2]);
    }
    void update(int start, int end, int ind, int q_ind, Update &u) {
        if (start == end) {
            u.apply(tree[ind]);
            return;
        }
        int mid = (start + end) / 2;
        if (mid >= q_ind)
            update(start, mid, 2*ind+1, q_ind, u);
        else
            update(mid+1, end, 2*ind+2, q_ind, u);
        tree[ind].merge(tree[2*ind+1], tree[2*ind+2]);
    }
    Node query(int start, int end, int ind, int left, int right) {
        if (start > right || end < left)
            return Node();
        if (start >= left && end <= right)
            return tree[ind];
        int mid = (start + end) / 2;
        Node l, r, ans;
        l = query(start, mid, 2*ind+1, left, right);
        r = query(mid+1, end, 2*ind+2, left, right);
        ans.merge(l, r);
        return ans;
    }
    void make_update(int ind, int val) {
        Update new_update = Update(val);
        update(0, n-1, 0, ind, new_update);
    }
    Node make_query(int left, int right) {
        return query(0, n-1, 0, left, right);
    }
};
struct Node {
    int val;
    Node() {
        val = 0;
    }
    Node(int p) {
        val = p;
    }
    void merge(Node &l, Node &r) {
        val = l.val + r.val;
    }
};
struct Update {
    int x;
    Update(int val) {
        x = val;
    }
    void apply(Node &a) {
        a.val = x;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i=0; i<n; i++) { cin >> a[i]; }
    SegTree <Node, Update> sgt(n, a);
}
