#include <bits/stdc++.h>

using i64 = long long;

struct Node {
    std::vector<int> edge;
};

void solve() {
    int n, k;
    std::cin >> n >> k;

    std::vector<Node> tree(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        u--; v--;
        tree[u].edge.push_back(v);
        tree[v].edge.push_back(u);
    }

    int curNeed, curK;
    auto dfs = [&](auto self, int i, int from) -> int {
        int remainSum = 1;
        std::vector<int> remain;
        for (auto to : tree[i].edge) {
            if (to == from) { continue; }
            int sz = self(self, to, i);
            remainSum += sz;
            remain.push_back(sz);
        }

        std::sort(remain.begin(), remain.end());
        int need = k - curK;
        for (auto curRemain : remain) {
            if (need == 0) { break; }
            if (curRemain >= curNeed) {
                need -= 1;
                curK += 1;
                remainSum -= curRemain;
            }
        }

        return remainSum;
    };

    int l = 1, r = n;
    while (l + 1 != r) {
        int mid = (l + r) >> 1;
        curNeed = mid, curK = 0;
        int sz = dfs(dfs, 0, -1);
        if (curK < k || sz < mid) {
            r = mid;
        } else {
            l = mid;
        }
    }

    std::cout << l << '\n';
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
