#include <bits/stdc++.h>

using i64 = int64_t;

struct Node {
    std::vector<int> children;
};

void solve() {
    int n;
    std::cin >> n;

    std::vector<Node> tree(n);
    for (int i = 1, u; i < n; i++) {
        std::cin >> u;
        u--;
        tree[u].children.push_back(i);
    }

    std::vector<int> sz(n);
    auto calSize = [&](auto self, int u) -> void {
        sz[u] = 1;
        for (auto child : tree[u].children) {
            self(self, child);
            sz[u] += sz[child];
        }
    };
    calSize(calSize, 0);

    auto dfs = [&](auto self, int u) -> int {
        if (sz[u] == 1) {
            return 0;
        }

        int mxNodeId = -1, s = 0;
        for (auto child : tree[u].children) {
            s += sz[child];
            if (mxNodeId == -1 || sz[child] > sz[mxNodeId]) {
                mxNodeId = child;
            }
        }

        if (sz[mxNodeId] <= s - sz[mxNodeId]) {
            return s - s % 2;
        }

        int mxNodeComb = self(self, mxNodeId);
        int need = 2 * sz[mxNodeId] - s;
        if (mxNodeComb >= need) {
            return (s - need) + (need - need % 2);
        }
        return (s - sz[mxNodeId]) * 2 + mxNodeComb;
    };

    std::cout << dfs(dfs, 0) / 2 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
