#include <bits/stdc++.h>

using i64 = long long;

class ZhuLiu {
public:
    struct Edge {
        int u, v;
        i64 w;
    };

    int n;
    std::vector<Edge> edges;

    i64 sum;

    explicit ZhuLiu(const int n) : n(n), sum(0) {}

    void addEdge(const int u, const int v, const i64 w) {
        edges.push_back({u, v, w});
    }

    bool go(int root) {
        std::vector<int> belong(n + 1);
        for (int i = 1; i <= n; i++) { belong[i] = i; }

        std::vector<int> pre(n + 1, -1);
        std::vector<i64> weigh(n + 1, 0);

        int stkPtr = -1;
        std::vector<int> stk(n + 1);
        std::vector<bool> vis(n + 1, false);
        std::vector<bool> inStack(n + 1, false);

        int tot = n;
        while (true) {
            for (auto [u, v, w] : edges) {
                if (u != v && (pre[v] == -1 || w < weigh[v])) {
                    pre[v] = u;
                    weigh[v] = w;
                }
            }

            pre[root] = -1, weigh[root] = 0;
            for (int block = 1; block <= tot; block++) {
                if (block != root && pre[block] == -1) {
                    return false;
                }
                sum += weigh[block];
            }

            for (int i = 1; i <= tot; i++) { belong[i] = -1; }

            int loopCnt = 0;
            for (int block = 1; block <= tot; block++) {
                if (vis[block]) { continue; }

                for (int curBlock = block; curBlock != -1; curBlock = pre[curBlock]) {
                    if (inStack[curBlock]) {
                        loopCnt += 1;
                        while (stk[stkPtr] != curBlock) {
                            belong[stk[stkPtr]] = loopCnt;
                            inStack[stk[stkPtr]] = false;
                            stkPtr -= 1;
                        }
                        belong[curBlock] = loopCnt;
                        break;
                    }
                    if (vis[curBlock]) { break; }

                    vis[curBlock] = true;
                    inStack[curBlock] = true;
                    stk[++stkPtr] = curBlock;
                }

                while (stkPtr >= 0) {
                    inStack[stk[stkPtr]] = false;
                    stkPtr -= 1;
                }
            }
            if (loopCnt == 0) { break; }

            for (int block = 1; block <= tot; block++) {
                if (belong[block] == -1) {
                    belong[block] = ++loopCnt;
                }
            }
            tot = loopCnt;

            for (auto &edge : edges) {
                int u = edge.u, v = edge.v;
                edge.u = belong[u], edge.v = belong[v];
                if (belong[u] != belong[v]) {
                    edge.w -= weigh[v];
                }
            }

            root = belong[root];
            for (int block = 1; block <= loopCnt; block++) { vis[block] = false; }
            for (int block = 1; block <= loopCnt; block++) { pre[block] = -1; }
        }

        return true;
    }
};

void solve() {
    int n, m, r;
    std::cin >> n >> m >> r;

    ZhuLiu zhuliu(n);
    for (int i = 0, u, v, w; i < m; i++) {
        std::cin >> u >> v >> w;
        zhuliu.addEdge(u, v, w);
    }

    if (!zhuliu.go(r)) {
        std::cout << -1 << '\n';
        return;
    }
    std::cout << zhuliu.sum << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
