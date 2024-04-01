#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> v(n), p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        p[i]--;
    }

    std::vector<int> mushrooms(n);
    for (int i = 0; i < n; i++) {
        mushrooms[i] = i;
    }
    std::sort(mushrooms.begin(), mushrooms.end(), [&](int a, int b) -> bool {
        return v[a] < v[b];
    });

    i64 ans = 0;
    int mxCnt = 0, ptr = n - 1;
    std::multiset<int> picked;
    std::vector<bool> used(n, false);
    for (int cnt = 1; cnt <= n && ptr >= 0; cnt++) {
        if (cnt >= 2) {
            if (used[p[cnt - 2]]) {
                picked.erase(picked.find(v[p[cnt - 2]]));
            }
            v[p[cnt - 2]] = 0;
        }

        while (ptr >= 0 && picked.size() < cnt) {
            if (v[mushrooms[ptr]] != 0) {
                picked.insert(v[mushrooms[ptr]]);
                used[mushrooms[ptr]] = true;
            }
            ptr -= 1;
        }

        i64 curAns = (i64) picked.size() * *picked.begin();
        if (curAns > ans) {
            ans = curAns;
            mxCnt = cnt;
        }
    }

    std::cout << ans << ' ' << mxCnt << '\n';
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
