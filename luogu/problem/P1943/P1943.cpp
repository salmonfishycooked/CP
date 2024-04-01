#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

void solve() {
    int N, C1, C2, C3;
    std::cin >> N >> C1 >> C2 >> C3;

    std::vector<std::pair<int, int>> pears(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        std::cin >> a >> b;
        pears[i].first = a, pears[i].second = b;
    }

    std::sort(pears.begin(), pears.end(), [&](std::pair<int, int> &x, std::pair<int, int> &y) -> bool {
        return x.second > y.second;
    });

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int a0 = pears[i].first, b0, K;
        std::priority_queue<int> q;
        for (int j = 0; j < N; j++) {
            b0 = pears[j].second;
            K = C1 * a0 + C2 * b0 + C3;

            auto [aj, bj] = pears[j];
            if (aj >= a0 && C1 * aj + C2 * bj <= K) {
                q.push(C1 * aj + C2 * bj);
            }
            while (!q.empty() && q.top() > K) {
                q.pop();
            }
            ans = std::max(ans, (int) q.size());
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
