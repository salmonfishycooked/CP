#include <iostream>
#include <vector>
#include <iomanip>

double pow(double a, int x) {
    double res = 1;
    for (; x; x >>= 1) {
        if (x & 1) {
            res *= a;
        }
        a *= a;
    }
    return res;
}

void solve() {
    int N;
    std::cin >> N;

    double l, r;
    std::cin >> l >> r;

    std::vector<double> coe(N + 1);
    for (int i = 0; i <= N; i++) {
        std::cin >> coe[i];
    }

    auto f = [&](double x) -> double {
        double res = 0;
        for (int i = 0; i <= N; i++) {
            res += coe[i] * pow(x, N - i);
        }

        return res;
    };

    while (r - l >= 1e-6) {
        double mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;
        if (f(mid1) > f(mid2)) {
            r = mid2;
        } else {
            l = mid1;
        }
    }
    std::cout << std::fixed << std::setprecision(5) << l << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
