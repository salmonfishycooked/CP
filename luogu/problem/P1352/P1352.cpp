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

    std::vector<std::vector<int>> f(n, std::vector<int>(2, -1));
    std::function<int(int, int)> dfs;
    dfs = [&](int root, int choose) -> int {
        if (f[root][choose] != -1) {
            return f[root][choose];
        }

        int res = 0;
        if (choose == 1) {
            res += tree[root].v;
            for (auto child : tree[root].children) {
                res += dfs(child, 0);
            }
            return f[root][choose] = res;
        }

        for (auto child : tree[root].children) {
            res += std::max(dfs(child, 0), dfs(child, 1));
        }
        return f[root][choose] = res;
    };

    std::cout << std::max(dfs(root, 1), dfs(root, 0)) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
