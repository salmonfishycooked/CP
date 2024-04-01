#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

void solve() {
    int n, S, T;
    std::cin >> n >> S >> T;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    auto check = [&](double avg) -> bool {
        std::vector<double> pre(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + a[i - 1] - avg;
        }

        std::deque<int> q;
        q.push_back(0);
        for (int i = S; i <= n; i++) {
            while (!q.empty() && i - q.front() > T) {
                q.pop_front();
            }

            if (pre[i] - pre[q.front()] >= 0) {
                return true;
            }

            while (!q.empty() && pre[i - S + 1] < pre[q.back()]) {
                q.pop_back();
            }
            q.push_back(i - S + 1);
        }
        return false;
    };

    double l = -(1e4 + 1), r = 1e4 + 1;
    while (r - l >= 0.0001) {
        double mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    std::cout << std::fixed << std::setprecision(3) << l << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
