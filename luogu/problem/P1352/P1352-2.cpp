#include <bits/stdc++.h>

struct Node {
    std::vector<int> children;
    int v, pa;
};

void solve() {
    int n;
    std::cin >> n;

    std::vector<Node> tree(n);
    for (int i = 0; i < n; i++) {
        std::cin >> tree[i].v;
        tree[i].pa = -1;
    }

    for (int i = 1; i < n; i++) {
        int l, k;
        std::cin >> l >> k;
        l--; k--;
        tree[k].children.push_back(l);
        tree[l].pa = k;
    }

    int root = 0;
    while (tree[root].pa != -1) {
        root = tree[root].pa;
    }

    std::vector<int> bfsOrder(n);
    bfsOrder[0] = root;
    for (int i = 0, ptr = 1; ptr < n; i++) {
        for (auto child : tree[bfsOrder[i]].children) {
            bfsOrder[ptr++] = child;
        }
    }

    std::vector<std::vector<int>> f(n, std::vector<int>(2));
    for (int i = n - 1; i >= 0; i--) {
        int node = bfsOrder[i];
        f[node][0] = 0, f[node][1] = tree[node].v;
        for (auto child : tree[node].children) {
            f[node][0] += std::max(f[child][0], f[child][1]);
            f[node][1] += f[child][0];
        }
    }

    std::cout << std::max(f[root][0], f[root][1]) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
