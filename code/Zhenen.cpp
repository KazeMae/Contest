/**
 * @Author      KAZE_mae
 * @Website     https://cloudfall.top/
 * @Url         
 * @DateTime    
 */
// #include <bits/stdc++.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

using ll = long long;
using Ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T>
using pair2 = pair<T, T>;
using PII = pair<int, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B){ return (ull)rng() % B; }

#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl
#define abs(a) ((a) >= 0 ? (a) : -(a))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mem(a, b) memset(a, b, sizeof(a))
// #define max(a, b) ((a) > (b) ? (a) : (b))
// #define min(a, b) ((a) < (b) ? (a) : (b))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
#define per(i, n, a) for (int i = n; i >= a; --i)
#define pb push_back
// #define mp make_pair
#define fi first
#define se second
#define lowbit(x) (x&(-x))

const int N = 1000005; // 1e6 + 5
const int INF = 0x3f3f3f3f;
const long long LNF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-7;
const double PI = acos(-1.0);
const int MOD = 998244353;

// #define int long long

long long qmi(long long m, long long k, long long p = 9e18) {
    int res = 1 % p, t = m;
    while (k) {
        if (k&1) res = res * t % p;
        t = t * t % p, k >>= 1;
    }
    return res;
}
long long exgcd(long long a, long long b, long long &x, long long &y) {  
    if (!b) { x = 1; y = 0; return a; }  
    int d = exgcd(b, a % b, y, x);
    y -= (a/b) * x;  
    return d;
}


// #define int long long
pair<int, int> ct(int n, int mn) {
    int ans = 0, res = INF;
    int l = 1, r = n;
    while(l < r) {
        int mid = l + r >> 1;
        if(n / mid + (n % mid != 0) > mn) l = mid + 1;
        else r = mid;
    }
    return {l, n / (l + 1) + (n % (l + 1) != 0)};
}
int q(int n) {
    return n / 2 + n % 2;
}

unsigned float_abs(unsigned f) {
    unsigned exp_mask = 0x7F800000; // 指数部分的掩码
    unsigned frac_mask = 0x007FFFFF; // 尾数部分的掩码
    unsigned sign_mask = 0x80000000; // 符号位的掩码

    // 提取符号位
    unsigned sign = f & sign_mask;

    // 将符号位清零，得到绝对值的无符号表示
    unsigned abs_f = f & ~sign;

    // 判断是否为 NaN
    if ((abs_f & exp_mask) == exp_mask && (abs_f & frac_mask) != 0) {
        return f; // 如果是 NaN，直接返回 f
    } else {
        return abs_f; // 否则返回绝对值
    }
}

void solve();
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cout<< setiosflags(ios::fixed) << setprecision(6);
    // int _ = 1; cin>> _; while(_ --)
        solve();
  return 0;
}

// #define int long long
void solve() {
     float f = -3.14;

    // 将 float 类型转换为 unsigned 类型
    unsigned u = *(unsigned*)&f;

    // 计算绝对值
    unsigned abs_u = float_abs(u);

    // 将 unsigned 类型转换回 float 类型
    float abs_f = *(float*)&abs_u;

    printf("|%f| = %f\n", f, abs_f);

}


struct C2 {
    int l, r; 
    // l 存左儿子下标, r 存右儿子下标
} tree[N];
