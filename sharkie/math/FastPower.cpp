// 快速幂取模 (Fast Power)
// 时间复杂度: O(logU)。其中 U 为幂的值（也就是参数 n）的大小
// 空间复杂度: O(1)

using i64 = long long;

i64 power(i64 x, int n, int m) {
    i64 res = 1;
    for (; n; n >>= 1) {
        if (n & 1) { res = res * x % m; }
        x = x * x % m;
    }

    return res;
}
