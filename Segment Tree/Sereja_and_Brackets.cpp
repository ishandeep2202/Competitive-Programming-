#include <bits/stdc++.h>

struct Node {
    int open{0};
    int close{0};
    int val{0};
};

class SegTree {
    std::string s;
    std::vector <Node> sgt;
public:    
    SegTree(std::string S) {
        s = S;
        int n = S.size();
        sgt = std::vector <Node> (4*n);
    }
    void build(int ind, int low, int high);
    Node query(int ind, int low, int high, int left, int right);
};

void SegTree::build(int ind, int low, int high) {
    if (low == high) {
        if (s[low] == '(') sgt[ind].open += 1;
        else sgt[ind].close += 1;
        return;
    }
    int mid = (low + high) / 2;
    build(2*ind+1, low, mid);
    build(2*ind+2, mid+1, high);
    sgt[ind].val = sgt[2*ind+1].val + sgt[2*ind+2].val + 2*std::min(sgt[2*ind+1].open, sgt[2*ind+2].close);
    sgt[ind].open = sgt[2*ind+2].open + sgt[2*ind+1].open - std::min(sgt[2*ind+1].open, sgt[2*ind+2].close);
    sgt[ind].close = sgt[2*ind+1].close + sgt[2*ind+2].close - std::min(sgt[2*ind+1].open, sgt[2*ind+2].close);
}

Node SegTree::query(int ind, int low, int high, int left, int right) {
    if (right < low || left > high) {
        return Node{};
    }
    if (low >= left && high <= right) {
        return sgt[ind];
    }
    int mid = (low + high) / 2;
    Node l_node = query(2*ind+1, low, mid, left, right);
    Node r_node = query(2*ind+2, mid+1, high, left, right);
    Node c_node{};
    c_node.val = l_node.val + r_node.val + 2*std::min(l_node.open, r_node.close);
    c_node.open = r_node.open + l_node.open - std::min(l_node.open, r_node.close);
    c_node.close = l_node.close + r_node.close - std::min(l_node.open, r_node.close);
    return c_node;
}

int main() {
    int q;
    std::string s;
    std::cin >> s >> q;
    int n = s.size();
    SegTree SGT{s};
    SGT.build(0, 0, n-1);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        l--; r--;
        std::cout << SGT.query(0, 0, n-1, l, r).val << '\n';
    }
}
