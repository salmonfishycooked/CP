#include <bits/stdc++.h>

bool inited = false;
std::vector<bool> f;

void init() {
    std::vector<int> nums(1, 1);
    for (int i = 2; i <= 5; i++) {
        int sz = (int) nums.size();
        int base = (int) std::pow(10, i - 1);
        nums.push_back(base);
        for (int j = 0; j < sz; j++) {
            nums.push_back(base + nums[j]);
        }
    }
    nums.push_back(100000);

    f.assign(1e5 + 1, false);
    f[1] = true;
    for (int i = 2; i <= 1e5; i++) {
        for (auto num : nums) {
            if (num > i || f[i]) {
                break;
            }
            if (i % num == 0) {
                f[i] = f[i / num];
            }
        }
    }
}

void solve() {
    int n;
    std::cin >> n;

    if (!inited) {
        inited = true;
        init();
    }

    std::cout << (f[n] ? "YES" : "NO") << '\n';
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
