#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    static constexpr int ROXY = 0;
    struct Node { int left, right, v; };

    int ROOT;
    std::vector<Node> tree;

    void init() {
        ROOT = 1;
        tree.resize(1);
        // tree.push_back({ROXY, ROXY, -1});
    }

    void buildTree(std::vector<int> &inorder, std::vector<int> &postorder) {
        std::vector<int> m(10000);
        for (int i = inorder.size() - 1; i >= 0; i--) { m[inorder[i]] = i; }

        int idx = postorder.size() - 1;
        auto build = [&](auto self, int l, int r) -> int {
            if (l > r) { return ROXY; }

            int me = (int) tree.size();
            tree.push_back({ROXY, ROXY, postorder[idx--]});

            tree[me].right = self(self, m[tree[me].v] + 1, r);
            tree[me].left = self(self, l, m[tree[me].v] - 1);

            return me;
        };

        build(build, 0, inorder.size() - 1);
    }

    int traverse() {
        int mn = INT_MAX, mnId, v = 0;
        auto go = [&](auto self, int root) -> void {
            v += tree[root].v;
            if (tree[root].left == ROXY && tree[root].right == ROXY) {
                if (v < mn) {
                    mn = v;
                    mnId = tree[root].v;
                }
            }

            if (tree[root].left != ROXY) { self(self, tree[root].left); }
            if (tree[root].right != ROXY) { self(self, tree[root].right); }
            v -= tree[root].v;
        };
        go(go, ROOT);

        return mnId;
    }

    void solve() {
        std::string inorder, postorder;
        while (std::getline(std::cin, inorder) && std::getline(std::cin, postorder)) {
            init();
            std::stringstream s1(inorder), s2(postorder);
            std::vector<int> in, po;
            for (int v1, v2; ;) {
                if (s1 >> v1 && s2 >> v2) {
                    in.push_back(v1);
                    po.push_back(v2);
                    continue;
                }
                break;
            }

            buildTree(in, po);
            std::cout << traverse() << '\n';
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
