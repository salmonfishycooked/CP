/**
 * ModInv（模乘操作下的求逆元，带缓存）
 * 使用了费马小定理（注意模数 mod 和需要求逆元的数 num 的限制，即费马小定理的应用前提）
 * 时间复杂度：O(log(mod))
 *
 * 适用于需要求逆元的一组数中，数的大小随机不定。否则，比如说像求 [1, n] 内的所有模乘逆元，线性递推逆元更为合适。
 */

#include <bits/stdc++.h>

using i64 = long long;

class ModInv {
public:
    const int mod;
    std::map<int, int> cache;

    explicit ModInv(int mod) : mod(mod) {}

    int operator()(int num) {
        auto it = cache.find(num);
        if (it != cache.end()) { return it->second; }

        return cache[num] = (int) power(num, mod - 2);
    }

    i64 power(i64 x, int n) const {
        i64 res = 1;
        for (; n; n >>= 1) {
            if (n & 1) { res = res * x % mod; }
            x = x * x % mod;
        }

        return res;
    }
};
