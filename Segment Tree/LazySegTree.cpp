#include <bits/stdc++.h>

class LazySegTree {
    std::vector <int> sgt, lazy;
    std::vector <int>& a;
public:
    LazySegTree (std::vector <int>& A) : a{A} {
        int n = A.size();
        sgt = std::vector <int> (4*n, 0);
        lazy = std::vector <int> (4*n, 0);
    }
    void build(int ind, int low, int high);
    int query(int ind, int low, int high, int left, int right);
    void update(int ind, int low, int high, int left, int right, int val);
};

void LazySegTree::build(int ind, int low, int high) {
    if (low == high) {
        sgt[ind] = a[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2*ind+1, low, mid);
    build(2*ind+2, mid+1, high);
    sgt[ind] = sgt[2*ind+1] + sgt[2*ind+2];
}

int LazySegTree::query(int ind, int low, int high, int left, int right) {
    if (lazy[ind] != 0) {
        sgt[ind] += (high - low + 1) * lazy[ind];
        if (low != high) {
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if (right < low || left > high) {
        return 0;
    }
    if (low >= left && high <= right) {
        return sgt[ind];
    }
    int mid = (low + high) / 2;
    int l_ans = query(2*ind+1, low, mid, left, right);
    int r_ans = query(2*ind+2, mid+1, high, left, right);
    return l_ans + r_ans;
}

void LazySegTree::update(int ind, int low, int high, int left, int right, int val) {
    if (lazy[ind] != 0) {
        sgt[ind] += (high - low + 1) * lazy[ind];
        if (low != high) {
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if (right < low || left > high) {
        return;
    }
    if (low >= left && high <= right) {
        sgt[ind] += (high - low + 1) * val;
        if (low != high) {
            lazy[2*ind+1] += val;
            lazy[2*ind+2] += val;
        }
        return;
    }
    int mid = (low + high) / 2;
    update(2*ind+1, low, mid, left, right, val);
    update(2*ind+2, mid+1, high, left, right, val);
    sgt[ind] = sgt[2*ind+1] + sgt[2*ind+2];
}
