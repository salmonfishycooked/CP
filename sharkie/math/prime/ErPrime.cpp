/**
 * 埃式筛
 *
 * 方法说明：
 * 1. void cal(int n) 计算 1 ~ n 之间的所有素数，将结果有序存储在 prime 数组里面。
 *
 * 时间复杂度：O(nlog(logn))
 */

#include <bits/stdc++.h>

using i64 = long long;

class ErPrime {
public:
    std::vector<int> prime;

    void cal(int n) {
        prime.resize(0);
        if (n >= 2) {
            prime.push_back(2);
        }

        std::vector<bool> vis(n + 1);
        for (int i = 3; i <= n; i += 2) {
            if (vis[i]) { continue; }
            prime.push_back(i);
            i64 next = (i64) i * i;
            while (next <= n) {
                vis[next] = true;
                next += i;
            }
        }
    }
};
