#include <bits/stdc++.h>

using i64 = int64_t;

class EuPrime {
public:
    std::vector<int> prime;

    void cal(int n) {
        prime.resize(0);

        std::vector<bool> vis(n + 1);
        for (int i = 2; i <= n; i++) {
            if (!vis[i]) {
                prime.push_back(i);
            }
            for (auto num : prime) {
                int v = i * num;
                if (v > n) { break; }
                vis[i * num] = true;
                if (i % num == 0) { break; }
            }
        }
    }
};

void solve() {
    int n, q;
    std::cin >> n >> q;

    EuPrime eu;
    eu.cal(n);
    int pos;
    while (q--) {
        std::cin >> pos;
        pos--;
        std::cout << eu.prime[pos] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
