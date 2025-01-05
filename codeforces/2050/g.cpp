#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    static constexpr int ROXY = 0, ROOT = 1;
    struct Node {
        std::vector<int> children;
    };

    void solve() {
        int n;
        std::cin >> n;

        std::vector<Node> tree(n + 1);
        for (int i = 1, u, v; i < n; i++) {
            std::cin >> u >> v;
            tree[u].children.push_back(v);
            tree[v].children.push_back(u);
        }

        auto delFather = [&](auto self, int cur, int fa) -> void {
            for (int i = tree[cur].children.size() - 1; i >= 0; i--) {
                if (tree[cur].children[i] == fa) {
                    tree[cur].children.erase(tree[cur].children.begin() + i);
                    break;
                }
            }
            for (auto child : tree[cur].children) { self(self, child, cur); }
            if (tree[cur].children.empty()) { tree[cur].children.push_back(ROXY); }
        };
        delFather(delFather, ROOT, 0);

        std::vector<int> f1(n + 1, 1);
        f1[ROXY] = 0;
        auto dfs1 = [&](auto self, int cur) -> void {
            if (cur == ROXY) { return; }
            for (auto child : tree[cur].children) {
                self(self, child);
                f1[cur] = std::max(f1[cur], f1[child] + (int) tree[cur].children.size() - 1);
            }
        };
        dfs1(dfs1, ROOT);

        std::vector<int> f2(n + 1, 0);
        auto dfs2 = [&](auto self, int cur) -> void {
            if (cur == ROXY) { return; }
            int no1 = 0, no2 = 0;
            for (auto child : tree[cur].children) {
                if (f1[child] > no2) {
                    no2 = f1[child];
                    if (no2 > no1) { std::swap(no1, no2); }
                }
                self(self, child);
            }
            f2[cur] = no1 + no2;
        };
        dfs2(dfs2, ROOT);

        auto dfs3 = [&](auto self, int cur) -> int {
            if (cur == ROXY) { return INT_MIN / 2; }

            int res = INT_MIN / 2;
            for (auto child : tree[cur].children) { res = std::max(res, self(self, child)); }
            res = std::max(res, f2[cur] + (cur != ROOT) + std::max(0, (int) tree[cur].children.size() - 2));

            return res;
        };

        std::cout << dfs3(dfs3, ROOT) << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    int t;
    std::cin >> t;

    while (t--) { s.solve(); }

    return 0;
}
