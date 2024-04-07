#include <bits/stdc++.h>

void solve() {
    int N;
    std::cin >> N;

    std::vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        std::cin >> X[i] >> Y[i];
    }

    for (int i = 0; i < N; i++) {
        int minDis = 0, id;
        for (int j = 0; j < N; j++) {
            if (j == i) { continue; }
            int dis = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]);
            if (dis > minDis) {
                id = j;
                minDis = dis;
            }
        }
        std::cout << id + 1 << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
