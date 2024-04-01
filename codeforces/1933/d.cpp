#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) { std::cin >> arr[i]; }

    int mn = *std::min_element(arr.begin(), arr.end());
    int cntMn = (int) std::count(arr.begin(), arr.end(), mn);
    if (cntMn == 1) {
        std::cout << "YES" << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] % mn != 0) {
            std::cout << "YES" << '\n';
            return;
        }
    }

    std::cout << "NO" << '\n';
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
