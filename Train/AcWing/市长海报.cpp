/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: 市长海报
| Contest: AcWing
| URL:     https://www.acwing.com/problem/content/4344/
| When:    2023-11-15 23:41:55
| 
| Memory:  64 MB
| Time:    1000 ms
*******************************/

/*
* ⣇⣿⠘⣿⣿⣿⡿⡿⣟⣟⢟⢟⢝⠵⡝⣿⡿⢂⣼⣿⣷⣌⠩⡫⡻⣝⠹⢿⣿⣷
* ⡆⣿⣆⠱⣝⡵⣝⢅⠙⣿⢕⢕⢕⢕⢝⣥⢒⠅⣿⣿⣿⡿⣳⣌⠪⡪⣡⢑⢝⣇
* ⡆⣿⣿⣦⠹⣳⣳⣕⢅⠈⢗⢕⢕⢕⢕⢕⢈⢆⠟⠋⠉⠁⠉⠉⠁⠈⠼⢐⢕⢽
* ⡗⢰⣶⣶⣦⣝⢝⢕⢕⠅⡆⢕⢕⢕⢕⢕⣴⠏⣠⡶⠛⡉⡉⡛⢶⣦⡀⠐⣕⢕
* ⡝⡄⢻⢟⣿⣿⣷⣕⣕⣅⣿⣔⣕⣵⣵⣿⣿⢠⣿⢠⣮⡈⣌⠨⠅⠹⣷⡀⢱⢕
* ⡝⡵⠟⠈⢀⣀⣀⡀⠉⢿⣿⣿⣿⣿⣿⣿⣿⣼⣿⢈⡋⠴⢿⡟⣡⡇⣿⡇⡀⢕
* ⡝⠁⣠⣾⠟⡉⡉⡉⠻⣦⣻⣿⣿⣿⣿⣿⣿⣿⣿⣧⠸⣿⣦⣥⣿⡇⡿⣰⢗⢄
* ⠁⢰⣿⡏⣴⣌⠈⣌⠡⠈⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣬⣉⣉⣁⣄⢖⢕⢕⢕
* ⡀⢻⣿⡇⢙⠁⠴⢿⡟⣡⡆⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣵⣵⣿
* ⡻⣄⣻⣿⣌⠘⢿⣷⣥⣿⠇⣿⣿⣿⣿⣿⣿⠛⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
* ⣷⢄⠻⣿⣟⠿⠦⠍⠉⣡⣾⣿⣿⣿⣿⣿⣿⢸⣿⣦⠙⣿⣿⣿⣿⣿⣿⣿⣿⠟
* ⡕⡑⣑⣈⣻⢗⢟⢞⢝⣻⣿⣿⣿⣿⣿⣿⣿⠸⣿⠿⠃⣿⣿⣿⣿⣿⣿⡿⠁⣠
* ⡝⡵⡈⢟⢕⢕⢕⢕⣵⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣿⣿⣿⣿⣿⠿⠋⣀⣈⠙
* ⡝⡵⡕⡀⠑⠳⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⢉⡠⡲⡫⡪⡪⡣
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
#define mp make_pair
#define fi first
#define se second
#define lowbit(x) (x&(-x))
// #define size(x) ((int)x.size())

const int N = 10000005; // 1e6 + 5
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
        int val = 0, t = 0;
    };
    vector<Zhenen> seg;

    SEGT(int n) : seg(n * 4) {}

    void update (int id) {
        seg[id].val = seg[rs].val;
    }

    void pushdown (int id) {
        if(seg[id].t == 0) return;
        seg[ls].val = seg[id].t;
        seg[rs].val = seg[id].t;
        seg[ls].t = seg[id].t;
        seg[rs].t = seg[id].t;
        seg[id].t = 0;
    }

    void modify (int id, int l, int r, int ql, int qr, int t) {
        if (ql == l && qr == r) {
            seg[id].val = t;
            seg[id].t = t;
        }else {
            pushdown(id);
            int mid = l + r >> 1;
            if(qr <= mid) modify(ls, l, mid, ql, qr, t);
            else if(ql > mid) modify(rs, mid + 1, r, ql, qr, t);
            else {
                modify(ls, l, mid, ql, mid, t);
                modify(rs, mid + 1, r, mid + 1, qr, t);
            }
            update(id);
        }
    }

    int query(int id, int l, int r, int ql, int qr) {
        if(ql == l && qr == r) return seg[id].val;
        int mid = l + r >> 1;
        pushdown(id);
        if(qr <= mid) return query(ls, l, mid, ql, qr);
        else if(ql > mid) return query(rs, mid + 1, r, ql, qr);
        else return (query(ls, l, mid, ql, mid) + query(rs, mid + 1, r, mid + 1, qr));
    }

    #undef ls
    #undef rs
};


void solve();
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // cout<< setiosflags(ios::fixed) << setprecision(10);
    int _ = 1; cin>> _; while(_ --)
        solve();
  return 0;
}
// #define int long long

void solve() {
    int n, l, r, mx = 0;
    set<int> s;
    cin>> n;
    SEGT tr(N);
    for(int i = 1; i <= n; ++ i) {
        cin>> l >> r;
        mx = max(r, mx);
        tr.modify(1, 1, n, l, r, i);
    }
    for(int i = 1; i <= mx; ++ i) {
        int k = tr.query(1, 1, n, i, i);
        if(!k) s.insert(k);
    }
    cout << s.size() <<endl;
} 
