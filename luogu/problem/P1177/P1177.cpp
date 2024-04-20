#include <bits/stdc++.h>

using i64 = int64_t;

void solve() {
    int N;
    std::cin >> N;

    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    auto mergeSort = [&](auto self, int l, int r) -> void {
        if (l == r) { return; }

        int mid = (l + r) >> 1;
        self(self, l, mid);
        self(self, mid + 1, r);

        std::vector<int> helper(r - l + 1);
        int p1 = l, p2 = mid + 1;
        while (p1 <= mid || p2 <= r) {
            int pos = p1 + p2 - l - mid - 1;
            if (p1 > mid) {
                helper[pos] = a[p2++];
                continue;
            }
            if (p2 > r) {
                helper[pos] = a[p1++];
                continue;
            }

            if (a[p1] <= a[p2]) {
                helper[pos] = a[p1++];
                continue;
            }
            helper[pos] = a[p2++];
        }

        for (int i = l; i <= r; i++) {
            a[i] = helper[i - l];
        }
    };
    mergeSort(mergeSort, 0, N - 1);

    for (auto num : a) {
        std::cout << num << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
