#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    static constexpr int ROXY = 0, ROOT = 1;
    struct Node { int left, right, v; };
    std::vector<Node> tree;

    void init() { tree.resize(1); }

    void buildTree() {
        auto build = [&](auto self) -> int {
            int v;
            std::cin >> v;
            if (v == -1) { return ROXY; }

            int me = (int) tree.size();
            tree.push_back({ROXY, ROXY, v});
            tree[me].left = self(self);
            tree[me].right = self(self);

            return me;
        };
        build(build);
    }

    void solve() {
        for (int round = 1; ; round++) {
            init();
            buildTree();
            int n = (int) tree.size();
            if (n == 1) { break; }

            std::vector<i64> sum(2 * n);
            int leftMost = INT_MAX, rightMost = INT_MIN;
            auto dfs = [&](auto self, int cur, int x) -> void {
                if (cur == ROXY) { return; }

                leftMost = std::min(leftMost, x), rightMost = std::max(rightMost, x);
                sum[x] += tree[cur].v;
                self(self, tree[cur].left, x - 1);
                self(self, tree[cur].right, x + 1);
            };
            dfs(dfs, ROOT, n);

            std::cout << "Case " << round << ':' << '\n';
            for (int i = leftMost; i <= rightMost; i++) {
                std::cout << sum[i];
                if (i != rightMost) { std::cout << ' '; }
            }
            std::cout << '\n' << '\n';
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    s.solve();

    return 0;
}
