#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int n, c, d;
    std::cin >> n >> c >> d;

    std::map<int, int> cnt;
    for (int i = n * n, tmp; i > 0; i--) {
        std::cin >> tmp;
        cnt[tmp] += 1;
    }

    std::vector<int> matrix[n];
    for (int i = 0; i < n; i++) {
        matrix[i].resize(n);
    }
    matrix[0][0] = cnt.begin()->first;
    cnt[matrix[0][0]] -= 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) { continue; }
            std::_Rb_tree_iterator<std::pair<const int, int>> it;
            if (j > 0) {
                it = cnt.find(matrix[i][j - 1] + d);
            } else if (i > 0) {
                it = cnt.find(matrix[i - 1][j] + c);
            }

            if (it == cnt.end() || it->second == 0 ||
                i > 0 && it->first != matrix[i - 1][j] + c || j > 0 && it->first != matrix[i][j - 1] + d) {
                std::cout << "NO" << '\n';
                return;
            }
            matrix[i][j] = it->first;
            it->second -= 1;
        }
    }

    std::cout << "YES" << '\n';
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
