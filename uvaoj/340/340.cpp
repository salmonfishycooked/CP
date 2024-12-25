#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int round = 1, n;
    while ((std::cin >> n) && (n != 0)) {
        std::cout << "Game " << round << ':' << '\n';

        std::vector<int> a(n), cnt(10);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            cnt[a[i]] += 1;
        }

        while (1) {
            int match = 0, strongMatch = 0, finish = 1;
            std::vector<int> guess(n), myCnt(10);
            for (int i = 0; i < n; i++) {
                std::cin >> guess[i];
                myCnt[guess[i]] += 1;
                if (myCnt[guess[i]] <= cnt[guess[i]]) { match += 1; }
                if (guess[i] == a[i]) { strongMatch += 1; }

                if (guess[i] != 0) { finish = 0; }
            }
            if (finish) { break; }

            std::cout << "    (" << strongMatch << ',' << (match - strongMatch) << ')' << '\n';
        }

        round += 1;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
