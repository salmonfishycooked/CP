#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    const std::set<char> st = {'-', '|', ' ', '#'};

    static constexpr int ROXY = 0, ROOT = 1;
    struct Node {
        char name;
        std::vector<int> children;
    };

    std::vector<Node> tree;

    void buildTree() {
        tree.resize(1);
        std::vector<std::string> input;
        std::string str;
        while (std::getline(std::cin, str)) {
            if (str == "#") { break; }
            input.push_back(str);
        }

        std::queue<std::tuple<int, int, int>> q;
        for (int i = 0; i < input.size(); i += 3) {
            std::queue<std::tuple<int, int, int>> helper;
            for (int j = 0; j < input[i].size(); j++) {
                if (st.count(input[i][j])) { continue; }

                int me = tree.size();
                tree.push_back({input[i][j], {}});
                if (!q.empty()) {
                    if (j > std::get<2>(q.front())) { q.pop(); }
                    auto [fa, left, right] = q.front();
                    tree[fa].children.push_back(me);
                }

                if (i + 3 < input.size() && j < input[i + 1].size() && input[i + 1][j] == '|') {
                    int row = i + 2, left = j, right = j;
                    while (left > 0 && input[row][left - 1] == '-') { left -= 1; }
                    while (right < input[row].size() - 1 && input[row][right + 1] == '-') { right += 1; }
                    helper.emplace(me, left, right);
                }
            }

            if (helper.empty()) { break; }
            q = helper;
        }
    }

    void solve() {
        buildTree();

        std::cout << '(';
        auto dfs = [&](auto self, int cur) -> void {
            std::cout << tree[cur].name;
            std::cout << '(';
            for (auto child : tree[cur].children) { self(self, child); }
            std::cout << ')';
        };
        if (tree.size() > 1) { dfs(dfs, ROOT); }
        std::cout << ')';
        std::cout << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    int t;
    std::cin >> t;
    std::cin.ignore();

    while (t--) { s.solve(); }

    return 0;
}
