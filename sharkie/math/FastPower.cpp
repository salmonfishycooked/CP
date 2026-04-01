/**
 * 快速幂取模 (Fast Power)
 * 时间复杂度: O(logU)。其中 U 为幂的值（也就是参数 n）的大小
 * 空间复杂度: O(1)
 */

using i64 = long long;

i64 power(const int x, int n, const int m) {
    i64 res = 1, weight = x;
    for (; n; n >>= 1) {
        if (n & 1) { res = res * weight % m; }
        weight = weight * weight % m;
    }

    return res;
}
