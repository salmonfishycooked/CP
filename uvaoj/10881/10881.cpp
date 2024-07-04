#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int L, T, n;
    std::cin >> L >> T >> n;

    std::vector<std::pair<int, char>> a(n);
    std::vector<int> orders(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first >> a[i].second;
        orders[i] = i;
    }

    std::sort(orders.begin(), orders.end(), [&](int e1, int e2) -> bool {
        return a[e1].first < a[e2].first;
    });

    for (int i = 0; i < n; i++) {
        int op = a[i].second == 'R' ? 1 : -1;
        a[i].first += T * op;
    }
    std::sort(a.begin(), a.end());

    std::vector<std::pair<int, char>> ans(n);
    for (int i = 0; i < n; i++) {
        if (a[i].first < 0 || a[i].first > L) {
            ans[orders[i]] = {-1, 'F'};
            continue;
        }

        if (i < n - 1 && a[i].first == a[i + 1].first) {
            ans[orders[i]] = {a[i].first, 'T'};
            ans[orders[i + 1]] = {a[i].first, 'T'};
            i += 1;
            continue;
        }
        ans[orders[i]] = {a[i].first, a[i].second};
    }

    for (auto &[pos, state] : ans) {
        switch (state) {
            case 'F':
                std::cout << "Fell off" << '\n';
                break;
            case 'T':
                std::cout << pos << ' ' << "Turning" << '\n';
                break;
            default:
                std::cout << pos << ' ' << state << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    for (int i = 1; i <= t; i++) {
        std::cout << "Case #" << i << ':' << '\n';
        solve();
        std::cout << '\n';
    }

    return 0;
}
