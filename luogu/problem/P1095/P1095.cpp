#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int M, S, T;
    std::cin >> M >> S >> T;

    int dis = 0, curT = T;

    int iTime = std::min(M / 10, curT);
    if (iTime * 60 >= S) {
        curT -= S / 60 + (S % 60 ? 1 : 0);
        dis += (S / 60 + (S % 60 ? 1 : 0)) * 60;
    } else {
        M -= iTime * 10;
        curT -= iTime;
        dis += 60 * iTime;
    }

    while (M >= 2 && curT > 0 && dis < S) {
        int needTime = M >= 6 ? 1 : 2;
        int remainDis = S - dis, remainSec = remainDis / 17 + (remainDis % 17 ? 1 : 0);
        if (remainSec < needTime + 1 && remainSec <= curT) {
            dis += remainSec * 17;
            curT -= remainSec;
            break;
        }
        if (needTime + 1 > curT) {
            dis += curT * 17;
            curT = 0;
            break;
        }
        curT -= needTime + 1;
        dis += 60;
        M = needTime * 4 + M - 10;
    }

    while (curT > 0 && dis < S) {
        int needTime = 5;
        int remainDis = S - dis, remainSec = remainDis / 17 + (remainDis % 17 ? 1 : 0);
        if (remainSec < needTime + 2 && remainSec <= curT) {
            dis += remainSec * 17;
            curT -= remainSec;
            break;
        }
        if (needTime + 2 > curT) {
            dis += curT * 17;
            curT = 0;
            break;
        }
        curT -= needTime + 2;
        dis += 120;
    }

    if (dis >= S) {
        std::cout << "Yes" << '\n';
        std::cout << T - curT << '\n';
        return;
    }
    std::cout << "No" << '\n';
    std::cout << dis << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
