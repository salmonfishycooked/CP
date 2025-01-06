#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    static constexpr int ROXY = 0, ROOT = 1;
    struct Node {
        int left, right;
        int weightL, disL, weightR, disR;
    };

    std::vector<Node> tree;
    std::vector<int> weight;

    void init() { tree.resize(1); }

    int buildTree() {
        int me = (int) tree.size();
        int wl, dl, wr, dr;
        std::cin >> wl >> dl >> wr >> dr;
        tree.push_back({ROXY, ROXY, wl, dl, wr, dr});
        if (wl == 0) { tree[me].left = buildTree(); }
        if (wr == 0) { tree[me].right = buildTree(); }

        return me;
    }

    void calc1() {
        weight.assign(tree.size(), 0);
        auto dfs = [&](auto self, int cur) -> void {
            if (cur == ROXY) { return; }

            self(self, tree[cur].left);
            self(self, tree[cur].right);
            weight[cur] = tree[cur].weightL + tree[cur].weightR + weight[tree[cur].left] + weight[tree[cur].right];
        };
        dfs(dfs, ROOT);
    }

    bool isBalanced(int cur) {
        auto &node = tree[cur];
        if (node.weightL != 0 && node.weightR != 0) { return node.weightL * node.disL == node.weightR * node.disR; }
        if (node.weightL == 0 && node.weightR != 0) {
            return isBalanced(node.left) && weight[node.left] * node.disL == node.weightR * node.disR;
        }
        if (node.weightL != 0 && node.weightR == 0) {
            return isBalanced(node.right) && node.weightL * node.disL == weight[node.right] * node.disR;
        }

        return isBalanced(node.left) && isBalanced(node.right) && weight[node.left] * node.disL == weight[node.right] * node.disR;
    }

    void solve() {
        init();
        buildTree();
        calc1();

        std::cout << (isBalanced(ROOT) ? "YES" : "NO") << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;
    int t;
    std::cin >> t;

    while (t--) {
        s.solve();
        if (t != 0) { std::cout << '\n'; }
    }

    return 0;
}
