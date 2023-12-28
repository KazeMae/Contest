/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: D - Swapping Puzzle
| Contest: AtCoder - AtCoder Beginner Contest 332
| URL:     https://atcoder.jp/contests/abc332/tasks/abc332_d
| When:    2023-12-11 02:16:30
| 
| Memory:  1024 MB
| Time:    2000 ms
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
int ans = -1;
int h, w;

void bfs(vector<int> sa, vector<int> b) {
    queue<pair<vector<int>, int> > q;
    q.push({sa, 0});
    set<vector<int>> st;
    st.insert(sa);
    while(!q.empty()) {
        auto [t, m] = q.front();
        q.pop();
        // cout<< m << " " << (t == b) <<endl;
        if(t == b) {
            ans = m;
            return;
        }
        for(int i = 0, j = 1; j < h; ++ i, ++ j) {
            auto tt = t;
            for(int k = 0; k < w; ++ k) {
                swap(tt[i * w + k], tt[j * w + k]);
            }
            if(tt == b) {
                ans = m + 1;
                return;
            }
            if(!st.count(tt)) q.push({tt, m + 1}), st.insert(tt);
        }
        for(int i = 0, j = 1; j < w; ++ i, ++ j) {
            auto tt = t;
            for(int k = 0; k < h; ++ k) {
                swap(tt[k * w + i], tt[k * w + j]);
            }
            if(tt == b) {
                ans = m + 1;
                return;
            }
            if(!st.count(tt)) q.push({tt, m + 1}), st.insert(tt);
        }
    }
}

void solve();
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // cout<< setiosflags(ios::fixed) << setprecision(10);
    // int _ = 1; cin>> _; while(_ --)
        solve();
  return 0;
}
// #define int long long

void solve() {
    cin>> h >> w;
    vector<int> a(h * w), b(h * w);
    for(int i = 0; i < h * w; ++ i) {
            cin>> a[i];
    }
    for(int i = 0; i < h * w; ++ i) {
            cin>> b[i];
    }
    bfs(a, b);
    cout<< ans <<endl;
} 
