#include <bits/stdc++.h>

using i64 = long long;

template <int sigma = 26, char start = 'a'>
class AhoCorasick {
public:
    struct Node {
        std::array<int, sigma> children;
        std::array<int, sigma> go;
        int fail;

        Node() {
            children.fill(NONE);
        }
    };

    int sz;
    std::vector<Node> nodes;
    static constexpr int ROOT = 0;
    static constexpr int NONE = -1;

    std::vector<int> bfsOrder;

    explicit AhoCorasick() : sz(1) {
        nodes.emplace_back();
    }

    int insert(const std::string &pat) {
        int cur = ROOT;
        for (auto ch : pat) {
            int next = ch - start;
            if (nodes[cur].children[next] == NONE) {
                nodes[cur].children[next] = sz++;
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

void solve() {
    int n;
    std::cin >> n;

    AhoCorasick ac;
    std::string tmp;
    std::vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        pos[i] = ac.insert(tmp);
    }

    ac.build();

    std::string s;
    std::cin >> s;

    std::vector<int> cnt(ac.sz);
    int cur = ac.ROOT;
    for (auto ch : s) {
        if (ch == 0) {
            cur = ac.ROOT;
        } else {
            cur = ac.nodes[cur].go[ch - 'a'];
        }
        cnt[cur] += 1;
    }

    for (int i = ac.bfsOrder.size() - 1; i >= 1; i--) {
        int id = ac.bfsOrder[i];
        cnt[ac.nodes[id].fail] += cnt[id];
    }

    for (auto p : pos) {
        std::cout << cnt[p] << '\n';
    }
    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
