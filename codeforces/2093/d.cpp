#include <bits/stdc++.h>

using i64 = long long;

class Solution {
public:
    void solve() {
        int n, q;
        std::cin >> n >> q;

        i64 edgeLen = std::pow(2, n);
        std::vector<int> dx = {0, 1, 1, 0}, dy = {0, 1, 0, 1};
        std::vector<std::vector<int>> states = {{2, 3}, {4, 1}};
        auto find1 = [&](i64 x, i64 y) -> void {
            i64 len = edgeLen, curX = 1, curY = 1, num = 1;
            while (len > 2) {
                len /= 2;
                int state = states[x - curX + 1 <= len][y - curY + 1 <= len];
                num += (len * len) * (state - 1);
                if (state == 2 || state == 3) { curX += len; }
                if (state == 2 || state == 4) { curY += len; }
            }

            for (int i = 0; i < 4; i++) {
                i64 nx = curX + dx[i], ny = curY + dy[i];
                if (nx == x && ny == y) {
                    std::cout << num << '\n';
                    return;
                }
                num += 1;
            }
        };

        auto find2 = [&](i64 target) -> void {
            i64 len = edgeLen, curX = 1, curY = 1, num = 1;
            while (len > 2) {
                len /= 2;
                i64 cnt = len * len;
                int state = 1;
                for (int i = 1; i <= 4; i++) {
                    if (num + cnt - 1 >= target) {
                        state = i;
                        break;
                    }
                    num += cnt;
                }
                if (state == 2 || state == 3) { curX += len; }
                if (state == 2 || state == 4) { curY += len; }
            }

            for (int i = 0; i < 4; i++) {
                i64 nx = curX + dx[i], ny = curY + dy[i];
                if (num == target) {
                    std::cout << nx << ' ' << ny << '\n';
                    return;
                }
                num += 1;
            }
        };

        std::string str;
        i64 num1, num2;
        while (q--) {
            std::cin >> str;
            if (str[1] == '>') {
                std::cin >> num1 >> num2;
                find1(num1, num2);
            } else {
                std::cin >> num1;
                find2(num1);
            }
        }
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
