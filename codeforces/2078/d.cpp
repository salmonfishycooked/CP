#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n;
        std::cin >> n;

        std::vector<std::pair<char, int>> a(n), b(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i].first >> a[i].second;
            std::cin >> b[i].first >> b[i].second;
        }

        i64 left = 1, right = 1, sum = 0;
        for (int i = 0; i < n; i++) {
            auto [op1, num1] = a[i];
            auto [op2, num2] = b[i];
            if (op1 != 'x' && op2 != 'x') {
                sum += num1 + num2;
                continue;
            }

            if (op1 == 'x' && op2 != 'x') {
                left += sum;
                sum = left * (num1 - 1) + num2;
                continue;
            }
            if (op1 != 'x' && op2 == 'x') {
                right += sum;
                sum = right * (num2 - 1) + num1;
                continue;
            }

            if (num1 > num2) {
                left += sum;
                sum = left * (num1 - 1) + right * (num2 - 1);
            } else if (num1 < num2) {
                right += sum;
                sum = left * (num1 - 1) + right * (num2 - 1);
            } else {
                sum += (left + right + sum) * (num1 - 1);
            }
        }

        std::cout << left + right + sum << '\n';
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    Solution s;

    int t;
    std::cin >> t;

    while (t--) { s.solve(); }

    return 0;
}
