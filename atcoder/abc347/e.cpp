#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> x(Q);
    std::vector<std::vector<int>> idx(N);
    for (int i = 0; i < Q; i++) {
        std::cin >> x[i];
        x[i] -= 1;
        idx[x[i]].push_back(i + 1);
    }

    int sz = 0;
    std::vector<bool> st(N, false);
    std::vector<i64> sum(Q + 1);
    for (int i = 1; i <= Q; i++) {
        if (st[x[i - 1]]) {
            st[x[i - 1]] = false;
            sz -= 1;
        } else {
            st[x[i - 1]] = true;
            sz += 1;
        }
        sum[i] = sum[i - 1] + sz;
    }

    for (int i = 0; i < N; i++) {
        i64 cur = 0;
        for (int j = 0; j < idx[i].size(); j += 2) {
            int l = idx[i][j], r = Q;
            if (j + 1 < idx[i].size()) { r = idx[i][j + 1] - 1; }
            cur += sum[r] - sum[l - 1];
        }
        std::cout << cur << ' ';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
