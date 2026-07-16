#include <bits/stdc++.h>

using namespace std;

class SegTree {
    vector <int> sgt;
    vector <int>& a;
public:
    SegTree(vector <int>& A) : a{A} {
        int n = A.size();
        sgt = vector <int> (4 * n, 0); 
    }
    void build(int, int, int);
    int query(int, int, int, int, int);
    void update(int, int, int, int, int);
};

void SegTree::build(int ind, int low, int high) {
    if (low == high) {
        sgt[ind] = a[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2*ind+1, low, mid);
    build(2*ind+2, mid+1, high);
    sgt[ind] = sgt[2*ind+1] + sgt[2*ind+2];
}

int SegTree::query(int ind, int low, int high, int left, int right) {
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

void SegTree::update(int ind, int low, int high, int pt, int val) {
    if (low == high) {
        a[low] = val;
        sgt[ind] = val;
        return;
    }
    if (pt < low || pt > high) {
        return;
    }
    int mid = (low + high) / 2;
    update(2*ind+1, low, mid, pt, val);
    update(2*ind+2, mid+1, high, pt, val);
    sgt[ind] = sgt[2*ind+1] + sgt[2*ind+2];
}

int main() {

}
