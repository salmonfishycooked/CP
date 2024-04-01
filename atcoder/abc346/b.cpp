#include <bits/stdc++.h>

void solve() {
    int W, B;
    std::cin >> W >> B;

    std::string s = "wbwbwwbwbwbw";
    for (int i = 0; i < s.size(); i++) {
        int cntW = 0, cntB = 0, ptr = i;
        while (cntW < W || cntB < B) {
            if (s[ptr] == 'b') {
                cntB += 1;
            } else {
                cntW += 1;
            }
            ptr = (ptr + 1) % s.size();
        }

        if (cntW == W && cntB == B) {
            std::cout << "Yes" << '\n';
            return;
        }
    }
    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
