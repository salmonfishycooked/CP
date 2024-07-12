#include <bits/stdc++.h>

using i64 = long long;

template <int sigma = 26, char start = 'a'>
class AhoCorasick {
public:
    struct Node {
        std::array<int, sigma> children;
        std::array<int, sigma> go;
        int fail;
        int cnt;

        Node() : fail(ROOT), cnt(0) {
            children.fill(NONE);
        }
    };

    std::vector<Node> nodes;
    static constexpr int ROOT = 0;
    static constexpr int NONE = -1;

    std::vector<int> bfsOrder;

    explicit AhoCorasick() {
        nodes.emplace_back();
    }

    int insert(const std::string &pat) {
        int cur = ROOT;
        for (auto ch : pat) {
            int next = ch - start;
            if (nodes[cur].children[next] == NONE) {
                nodes[cur].children[next] = nodes.size();
                nodes.emplace_back();
            }
            cur = nodes[cur].children[next];
        }

        return cur;
    }

    void build() {
        bfsOrder.push_back(ROOT);
        for (int ptr = 0; ptr < bfsOrder.size(); ptr++) {
            int cur = bfsOrder[ptr];
            for (int i = 0; i < sigma; i++) {
                if (nodes[cur].children[i] != NONE) {
                    nodes[cur].go[i] = nodes[cur].children[i];
                    if (cur == ROOT) {
                        nodes[nodes[cur].children[i]].fail = ROOT;
                    } else {
                        nodes[nodes[cur].children[i]].fail = nodes[nodes[cur].fail].go[i];
                    }

                    bfsOrder.push_back(nodes[cur].children[i]);
                } else {
                    if (cur == ROOT) {
                        nodes[cur].go[i] = ROOT;
                    } else {
                        nodes[cur].go[i] = nodes[nodes[cur].fail].go[i];
                    }
                }
            }
        }
    }
};

void solve(int n) {
    AhoCorasick ac;
    std::vector<std::string> strs(n);
    std::vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        std::cin >> strs[i];
        pos[i] = ac.insert(strs[i]);
    }

    ac.build();

    std::string s;
    std::cin >> s;

    int cur = ac.ROOT;
    for (auto ch : s) {
        cur = ac.nodes[cur].go[ch - 'a'];
        ac.nodes[cur].cnt += 1;
    }

    for (int i = ac.bfsOrder.size() - 1; i >= 1; i--) {
        int id = ac.bfsOrder[i];
        ac.nodes[ac.nodes[id].fail].cnt += ac.nodes[id].cnt;
    }

    int mx = INT_MIN;
    std::vector<int> ids;
    for (int i = 0; i < n; i++) {
        if (ac.nodes[pos[i]].cnt == mx) {
            ids.push_back(i);
        }
        if (ac.nodes[pos[i]].cnt > mx) {
            mx = ac.nodes[pos[i]].cnt;
            ids.clear();
            ids.push_back(i);
        }
    }

    std::cout << mx << '\n';
    for (auto id : ids) {
        std::cout << strs[id] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (std::cin >> n) {
        if (n == 0) { break; }
        solve(n);
    }

    return 0;
}
