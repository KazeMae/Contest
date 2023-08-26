/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: 中位数
| Contest: NowCoder
| URL:     https://ac.nowcoder.com/acm/contest/61132/L
| When:    2023-08-23 15:37:04
|
| Memory:  1048576 MB
| Time:    2000 ms
*******************************/

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

// #define int long long

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
ll myRand(ll B) { return (ull)rng() % B; }

#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl
#define abs(a) ((a) >= 0 ? (a) : -(a))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mem(a, b) memset(a, b, sizeof(a))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define rep(i, a, n) for (int i = a; i <= n; ++i)
#define per(i, n, a) for (int i = n; i >= a; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lowbit(x) x&(-x)

const int N = 1000005; // 1e6 + 5
const int INF = 0x3f3f3f3f;
const long long LNF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-7;
const double PI = acos(-1.0);
const int MOD = 998244353;

long long qmi(long long m, long long k, long long p = 9e18) {
    int res = 1 % p, t = m;
    while (k) {
        if (k & 1) res = res * t % p;
        t = t * t % p, k >>= 1;
    }
    return res;
}
inline long long gcd(long long a, long long b) {return b ? gcd(b, a % b) : a;}
long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (!b) { x = 1; y = 0; return a; }
    int d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

template<class T>
struct BIT {
    int n;
    vector<T> c;
    // 定义树状数组
    BIT(int len) : n(len), c(n + 1) {}
    // 初始化
    void init(vector<int> &a) {
        for (int i = 1, j = 0; i <= n; ++ i) {
            c[i] += a[i], j = i + ((i) & (-i));
            if (j <= n) c[j] += c[i];
        }
    }
    // 修改 a[x] += s
    void add(int x, T s) {
        assert(x != 0);
        for (; x <= n; x += ((x) & (- x)))
            c[x] += s;
    }
    // 查询 a[1]...a[x] 的和
    T sum(int x) {
        assert(x <= n);
        T sum = 0;
        for (; x; x -= ((x) & (- x)))
            sum += c[x];
        return sum;
    }
    // 查询 a[l]...a[r] 的和
    T getsum(int l, int r) {
        if (r < l) swap(l, r);
        return sum(r) - sum(l - 1);
    }
    // 查询最大的 pos, 满足 a[1]+...+a[t] <= s
    int find(T s) {
        int pos = 0;
        for (int j = 30; j >= 0; -- j) {
            if (pos + (1 << j) <= n && c[pos + (1 << j)] <= s) {
                pos += (1 << j);
                s -= c[pos];
            }
        }
        return pos;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
    }
    BIT<int> tree(n);
    while (m --) {
        int p, x;
        cin>> p >> x;
        tree.add(a[p], -1);
        tree.add(x, 1);
        a[p] = x;
        cout<< n / 2 + 1 << " " << tree.find(n / 2 + 1) <<endl;
    }
}
signed main() {
    // std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int _ = 1; cin>> _; while(_ --)
    solve();
    return 0;
}
