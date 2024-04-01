#include <iostream>
#include <vector>
#include <climits>

using i64 = unsigned long long;

constexpr int MAX_N = 1e5;

void solve() {
    i64 A, B, C, n, m;
    std::cin >> A >> B >> C >> n >> m;

    std::vector<int> t(n);
    for (int i = 0; i < n; i++) {
        std::cin >> t[i];
    }

    std::vector<int> b(m);
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    std::vector<i64> cntT(MAX_N + 1, 0);
    for (int i = 0; i < n; i++) {
        cntT[t[i]] += 1;
    }
    std::vector<i64> sumT(MAX_N + 1, 0);
    for (int i = 1; i <= MAX_N; i++) {
        sumT[i] = sumT[i - 1] + cntT[i] * i;
        cntT[i] += cntT[i - 1];
    }

    i64 sumExam = 0;
    std::vector<i64> cntB(MAX_N + 1, 0);
    for (int i = 0; i < m; i++) {
        cntB[b[i]] += 1;
        sumExam += b[i];
    }
    std::vector<i64> sumB(MAX_N + 1, 0);
    for (int i = 1; i <= MAX_N; i++) {
        sumB[i] = sumB[i - 1] + cntB[i] * i;
        cntB[i] += cntB[i - 1];
    }

    i64 minDissatisfaction = ULONG_LONG_MAX;
    for (i64 i = 1; i <= MAX_N; i++) {
        i64 dissatisfaction = (i * cntT[i] - sumT[i]) * C;
        i64 examLeftRemain = i * cntB[i] - sumB[i];
        i64 examRightNeed = sumExam - sumB[i] - i * (m - cntB[i]);
        if (A < B) {
            dissatisfaction += A * std::min(examRightNeed, examLeftRemain);
            if (examRightNeed > examLeftRemain) {
                dissatisfaction += B * (examRightNeed - examLeftRemain);
            }
        } else {
            dissatisfaction += B * examRightNeed;
        }

        minDissatisfaction = std::min(minDissatisfaction, dissatisfaction);
    }

    std::cout << minDissatisfaction << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
