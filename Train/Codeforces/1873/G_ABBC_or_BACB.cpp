/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: G. ABBC or BACB
| Contest: Codeforces Round 898 (Div. 4)
| URL:     https://codeforces.com/contest/1873/problem/G
| When:    2023-09-22 22:25:20
| 
| Memory:  256 MB
| Time:    1000 ms
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

void solve() {
    string s, rs;
    cin>> s;
    rs = s;
    int len = s.size(), cnt = 0, rcnt = 0, lrcnt = 0, rlcnt = 0;
    for(int i = len; i - 1 >= 0; -- i) {
        if(s[i - 1] == 'A' && s[i] == 'B') {
            s[i - 1] = 'B', s[i] = 'C', i = min(i + 2, len), rcnt ++;
        }else if(s[i - 1] == 'B' && s[i] == 'A') {
            s[i - 1] = 'C', s[i] = 'B', i = min(i + 2, len), rcnt ++;
        }
    }
    for(int i = len; i - 1 >= 0; -- i) {
        if(s[i - 1] == 'A' && s[i] == 'B') {
            s[i - 1] = 'B', s[i] = 'C', i = min(i + 2, len), rcnt ++;
        }else if(rs[i - 1] == 'B' && s[i] == 'A') {
            s[i - 1] = 'C', s[i] = 'B', i = min(i + 2, len), rcnt ++;
        }
    }
    s = rs;
    for(int i = 0; i + 1 < len; ++ i) {
        if(s[i] == 'A' && s[i + 1] == 'B') {
            s[i] = 'B', s[i + 1] = 'C', i = max(i - 2, 0), cnt ++;
        }else if(s[i] == 'B' && s[i + 1] == 'A') {
            s[i] = 'C', s[i + 1] = 'B', i = max(i - 2, 0), cnt ++;
        }
    }
    for(int i = 0; i + 1 < len; ++ i) {
        if(s[i] == 'A' && s[i + 1] == 'B') {
            s[i] = 'B', s[i + 1] = 'C', i = max(i - 2, 0), cnt ++;
        }else if(s[i] == 'B' && s[i + 1] == 'A') {
            s[i] = 'C', s[i + 1] = 'B', i = max(i - 2, 0), cnt ++;
        }
    }
    s = rs;
    for(int i = 0; i + 1 < len; ++ i) {
        if(s[i] == 'A' && s[i + 1] == 'B') {
            s[i] = 'B', s[i + 1] = 'C', i = max(i - 2, 0), lrcnt ++;
        }else if(s[i] == 'B' && s[i + 1] == 'A') {
            s[i] = 'C', s[i + 1] = 'B', i = max(i - 2, 0), lrcnt ++;
        }
    }
    for(int i = len; i - 1 >= 0; -- i) {
        if(s[i - 1] == 'A' && s[i] == 'B') {
            s[i - 1] = 'B', s[i] = 'C', i = min(i + 2, len), lrcnt ++;
        }else if(s[i - 1] == 'B' && s[i] == 'A') {
            s[i - 1] = 'C', s[i] = 'B', i = min(i + 2, len), lrcnt ++;
        }
    }
    s = rs;
    for(int i = len; i - 1 >= 0; -- i) {
        if(s[i - 1] == 'A' && s[i] == 'B') {
            s[i - 1] = 'B', s[i] = 'C', i = min(i + 2, len), rlcnt ++;
        }else if(s[i - 1] == 'B' && s[i] == 'A') {
            s[i - 1] = 'C', s[i] = 'B', i = min(i + 2, len), rlcnt ++;
        }
    }
    for(int i = 0; i + 1 < len; ++ i) {
        if(s[i] == 'A' && s[i + 1] == 'B') {
            s[i] = 'B', s[i + 1] = 'C', i = max(i - 2, 0), rlcnt ++;
        }else if(s[i] == 'B' && s[i + 1] == 'A') {
            s[i] = 'C', s[i + 1] = 'B', i = max(i - 2, 0), rlcnt ++;
        }
    }
    cout<< max({cnt, rcnt, lrcnt, rlcnt}) <<endl;
}
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1; cin>> _; while(_ --)
        solve();
  return 0;
}
