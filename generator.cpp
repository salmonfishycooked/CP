/**
 * Generator used to generate test cases
 */

#include <bits/stdc++.h>

using i64 = int64_t;

// CASES is used to tell the generator, how many test cases it should generate.
constexpr int CASES = 1;

class Generator {
private:
    std::mt19937_64 gen{std::random_device{}()};
public:
    /**
     * go is the main logic for generating.
     * following is a generating example.
     */
    void go() {
        std::uniform_int_distribution<i64> nDis{1, 300};
        std::uniform_int_distribution<i64> mDis{0, 1000000};
        std::uniform_int_distribution<i64> xDis{-2500000, 2500000};
        int n = nDis(gen), m = mDis(gen);
        std::uniform_int_distribution<i64> pDis{1, n};
        int p = pDis(gen);

        std::cout << n << ' ' << m << ' ' << p << '\n';
        for (int i = 0; i < n; i++) {
            std::cout << xDis(gen) << ' ';
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    freopen("e.in", "w", stdout);

    Generator generator;
    for (int i = 0; i < CASES; i++) {
        generator.go();
    }

    return 0;
}
