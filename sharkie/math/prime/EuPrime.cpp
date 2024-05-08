/**
 * 欧拉筛
 *
 * 方法说明：
 * 1. void cal(int n) 计算 1 ~ n 之间的所有素数，将结果有序存储在 prime 数组里面。
 *
 * 时间复杂度：O(n)
 */

#include <bits/stdc++.h>

class EuPrime {
public:
    std::vector<int> prime;

    void cal(int n) {
        prime.resize(0);

        std::vector<bool> vis(n + 1);
        for (int i = 2; i <= n; i++) {
            if (!vis[i]) {
                prime.push_back(i);
            }
            for (auto num : prime) {
                int v = i * num;
                if (v > n) { break; }
                vis[i * num] = true;
                if (i % num == 0) { break; }
            }
        }
    }
};
