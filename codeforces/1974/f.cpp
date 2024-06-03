#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int a, b, n, m;
    std::cin >> a >> b >> n >> m;

    std::set<int> rs, cs;
    std::map<int, std::vector<std::pair<int, int>>> rowP, colP;
    std::map<int, int> rowCnt, colCnt;
    for (int i = 0, x, y; i < n; i++) {
        std::cin >> x >> y;
        rs.insert(x);
        cs.insert(y);
        rowP[x].emplace_back(x, y);
        colP[y].emplace_back(x, y);
        rowCnt[x] += 1;
        colCnt[y] += 1;
    }

    char op;
    int num;
    int startR = 1, endR = a, startC = 1, endC = b;
    std::vector<int> ans(2);
    for (int q = 0; q < m; q++) {
        std::cin >> op >> num;
        if (op == 'U') {
            int from = startR, to = startR + num - 1;
            auto it1 = rs.lower_bound(from);
            auto it2 = rs.upper_bound(to);
            for (; it1 != it2; it1++) {
                ans[q % 2] += rowCnt[*it1];
                auto &points = rowP[*it1];
                for (auto [x, y] : points) {
                    colCnt[y] -= 1;
                }
            }
            startR = to + 1;
        } else if (op == 'D') {
            int from = endR - num + 1, to = endR;
            auto it1 = rs.lower_bound(from);
            auto it2 = rs.upper_bound(to);
            for (; it1 != it2; it1++) {
                ans[q % 2] += rowCnt[*it1];
                auto &points = rowP[*it1];
                for (auto [x, y] : points) {
                    colCnt[y] -= 1;
                }
            }
            endR = from - 1;
        } else if (op == 'R') {
            int from = endC - num + 1, to = endC;
            auto it1 = cs.lower_bound(from);
            auto it2 = cs.upper_bound(to);
            for (; it1 != it2; it1++) {
                ans[q % 2] += colCnt[*it1];
                auto &points = colP[*it1];
                for (auto [x, y] : points) {
                    rowCnt[x] -= 1;
                }
            }
            endC = from - 1;
        } else {
            int from = startC, to = startC + num - 1;
            auto it1 = cs.lower_bound(from);
            auto it2 = cs.upper_bound(to);
            for (; it1 != it2; it1++) {
                ans[q % 2] += colCnt[*it1];
                auto &points = colP[*it1];
                for (auto [x, y] : points) {
                    rowCnt[x] -= 1;
                }
            }
            startC = to + 1;
        }
    }

    std::cout << ans[0] << ' ' << ans[1] << '\n';
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
