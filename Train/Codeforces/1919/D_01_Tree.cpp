/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: D. 01 Tree
| Contest: Codeforces - Hello 2024
| URL:     https://codeforces.com/contest/1919/problem/D
| When:    2024-01-07 00:02:11
| 
| Memory:  256 MB
| Time:    1000 ms
*******************************/

/********************************************
|⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠛⠛⠛⠛⠛⠿⣿⣿⣿⣿⣿⣷⠀⣿⣿⣿⣿⣿⣿⣿⣿
|⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⠉⠀⠀⣠⣤⣤⣤⣤⣤⣤⣤⣀⠀⠉⠛⠿⠈⣦⠙⣿⣿⣿⣿⣿⣿⣿
|⣿⣿⣿⣿⣿⣿⠟⠀⢀⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣤⠀⣼⣿⣦⠙⣿⣿⣿⣿⣿⣿
|⣿⣿⣿⠿⠛⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⣿⣿⣿⠀⠻⣿⣿⣿⣿⣿
|⣿⡟⠀⠀⠤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⣿⣿⣿⠆⠀⠀⠙⣿⣿⣿
|⣿⣆⠀⠀⠀⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠿⢿⠿⠀⠀⠀⠀ ⣿⣿⣿
|⣿⣿⣦⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⣀⣤⣆⠀⢠⣿⣿⣿⣿
|⣿⣿⠋⠀⣿⣿⣿⣿⠋⠀⠈⢿⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣿⠉⠀⠈⣿⣿⣿⣿⡆⠈⣿⣿⣿⣿
|⣿⣿⠀⠸⠿⠿⣿⣿⠀⠀⠀⣸⣿⣿⡁⠀⠀⠀⠀⢙⣿⣿⣧⠀⠀⠀ ⢠⣿⡿⠿⠿ ⢹⣿⣿⣿
|⣟⠀⠀⠀⣀⠀⠀⠀⢙⣶⣾⣿⣿⣿⣿⣶⡄⢀⣴⣿⣿⣿⣿⣷⣶⡶⠁⠀⢀⠀⣀⠀⠀ ⢙⣿⣿
|⣿⠀⠻⠿⠛⠛⠛⠷⢾⣿⣿⣿⣿⣿⣿⣿⠇⠙⣿⣿⣿⣿⣿⣿⣿⣿⠒⠛⠛⠻⠿⢿⠀⢿⣿⣿
|⠟⠀⢀⢀⣤⣶⣶⣦⣾⣿⣿⣿⣿⣿⣿⢀⣶⣶⣀⠙⣿⣿⣿⣿⣿⣿⣦⣤⣶⣦⣄⠀⠀⠘⣿⣿
|⣷⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⣶⣿⣿
|⣿⣆⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⢠⣿⣿⣿
|⣿⣿⣄⠀⠙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠀⢀⣿⣿⣿⣿
|⣿⣿⣿⣷⡀⠈⠛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠋⠀⣴⣿⣿⣿⣿⣿
|⣿⣿⣿⣿⣿⣶⣀⠀⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠁⢀⣴⣿⣿⣿⣿⣿⣿⣿
|⣿⣿⣿⣿⣿⣿⣿⣿⣤⣀⠀⠉⠛⠛⠛⠛⠛⠛⠛⠛⠛⠛⠋⠀⣀⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿
|⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
*********************************************/

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
#define mp make_pair
#define fi first
#define se second
#define lowbit(x) (x&(-x))
#define size(x) ((int)x.size())

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
inline long long gcd(long long a, long long b) {return b ? gcd(b, a % b) : a;}
long long exgcd(long long a, long long b, long long &x, long long &y) {  
    if (!b) { x = 1; y = 0; return a; }  
    int d = exgcd(b, a % b, y, x);
    y -= (a/b) * x;  
    return d;
}

long long Sqrt(long long N) {
    __int128 sqrtN = sqrtl(N) - 1;
    while (sqrtN + 1 <= N / (sqrtN + 1))sqrtN++;
    return sqrtN;
}

// #define int long long
struct SEGT {
    #define ls id << 1
    #define rs id << 1 | 1
    struct Zhenen {
        long long val;
    };
    vector<int> a;
    vector<Zhenen> seg;
    SEGT(int n) : a(n + 1), seg(n * 4) {}

    void update(int id) {
        seg[id].val = max(seg[ls].val, seg[rs].val);
    }


    void pushdown(int id) {
        
    }

    void build(int id, int l, int r) {
        if(l == r) seg[id].val = a[l];
        else {
            int mid = l + r >> 1;
            build(ls, l, mid);
            build(rs, mid + 1, r);
            update(id);
        }
    }
    // 修改 [ql, qr] 为 t
    void modify(int id, int l, int r, int ql, int qr, long long t) {
        if(l == ql && r == qr) {
            seg[id].val = t;
            return;
        }
        // pushdown(id);
        int mid = l + r >> 1;
        if(qr <= mid) modify(ls, l , mid, ql, qr, t);
        else if(ql > mid) modify(rs, mid + 1, r, ql, qr, t);
        else {
            modify(ls, l, mid, ql, mid, t);
            modify(rs, mid + 1, r, mid + 1, qr, t);
        }
        update(id);
    }
    
    long long query(int id, int l, int r, int ql, int qr) {
        if(l == ql && r == qr) return seg[id].val;
        pushdown(id);
        int mid = l + r >> 1;
        if(qr <= mid) return query(ls, l, mid, ql, qr);
        else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
        else return (query(ls, l, mid, ql, mid) + query(rs, mid + 1, r, mid + 1, qr));
    }
    // 寻找 [ql, qr] 大于等于 d 的第一个数的下标, 不存在返回 -1
    int search(int id, int l, int r, int ql, int qr, int d) {
        if(l == ql && r == qr) {
            if(seg[id].val < d) return -1;
            else {
                if(l == r) return l;
                int mid = l + r >> 1;
                if(seg[ls].val >= d) return search(ls, l, mid, ql, mid, d);
                else return search(rs, mid + 1, r, mid + 1, qr, d);
            }
        }
        // pushdown(id);
        int mid = l + r >> 1;
        if(qr <= mid) return search(ls, l, mid, ql, qr, d);
        else if(ql > mid) return search(rs, mid + 1, r, ql, qr, d);
        else {
            int pos = search(ls, l, mid, ql, mid, d);
            if(pos == -1) return search(rs, mid + 1, r, mid + 1, qr, d);
            else return pos;
        }
    }
    #undef ls
    #undef rs
};

string solve();
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // cout<< setiosflags(ios::fixed) << setprecision(10);
    int _ = 1; cin>> _; while(_ --)
        cout << solve() <<endl;
  return 0;
}
// #define int long long

string solve() {
    int n, t;
    cin>> n;
    SEGT tr(n);
    for(int i = 0, x; i < n; ++ i) 
        cin>> x, tr.a[i + 1] = -x;
    tr.build(1, 1, n);
    for(int i = 1; i <= n; ++ i) {
        auto l = tr.search(1, 1, n, 1, i, tr.a[i]), r = tr.search(1, 1, n, i, n, tr.a[i]);
        if(l != -1 && r != -1 && tr.a[i] - tr.a[l] < -1 && tr.a[i] - tr.a[r] < -1) return "NO";
        else if(l != -1 && tr.a[i] - tr.a[l] < -1) return "NO";
        else if(r != -1 && tr.a[i] - tr.a[r] < -1) return "NO";
    }
    return "YES";
} 
