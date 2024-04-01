#include <iostream>

void solve() {
    int n;
    std::cin >> n;
    int sum = 0, tmp, cnt[3] = {0};
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        sum += tmp;
        cnt[tmp % 3] += 1;
    }

    int digitSum = 0;
    while (sum) {
        digitSum += sum % 10;
        sum /= 10;
    }

    if (digitSum % 3 == 0) {
        std::cout << 0 << '\n';
        return;
    }
    if (digitSum % 3 == 1 && cnt[1] > 0 || digitSum % 3 == 2) {
        std::cout << 1 << '\n';
        return;
    }
    std::cout << 2 << '\n';
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
