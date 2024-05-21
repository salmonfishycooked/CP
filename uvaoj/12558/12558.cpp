/**
 * UVA 12558 - Egyptian Fractions (HARD version)
 * 迭代加深搜索 (IDDFS) + 剪枝
 */

#include <bits/stdc++.h>

using i64 = int64_t;

void solve(int id) {
    i64 a, b, q;
    std::cin >> a >> b >> q;

    std::set<int> s;
    for (int i = 0, num; i < q; i++) {
        std::cin >> num;
        s.insert(num);
    }

    int depth;
    bool ok = false;
    std::vector<i64> ans, cur;
    auto dfs = [&](auto self, int i, i64 pre, i64 fz, i64 fm) {
        if (i > depth) {
            if (fz == 0) {
                ok = true;
                bool change = ans.empty();
                for (int j = depth - 1; j >= 0 && !change; j--) {
                    if (ans[j] != cur[j]) {
                        change = ans[j] > cur[j];
                        break;
                    }
                }
                if (change) { ans = cur; }
            }
            return;
        }

        for (i64 num = std::max(pre + 1, (i64) std::ceil((double) fm / fz)); ; num++) {
            if (fm * (depth - i + 1) < fz * num) { break; }
            if (s.count(num)) { continue; }
            cur.push_back(num);
            i64 nfz = fz * num - fm, nfm = fm * num;
            i64 div = std::gcd(nfz, nfm);
            nfz /= div, nfm /= div;
            self(self, i + 1, num, nfz, nfm);
            cur.pop_back();
        }
    };

    for (int i = 1; !ok; i++) {
        depth = i;
        dfs(dfs, 1, 0, a, b);
    }

    std::cout << "Case " << id << ": " << a << "/" << b << "=";
    for (int i = 0; i < ans.size(); i++) {
        std::cout << 1 << "/" << ans[i];
        if (i < ans.size() - 1) {
            std::cout << '+';
        }
    }
    std::cout << '\n';
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    for (int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;
}
