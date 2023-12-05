/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: D. Jumping Through Segments
| Contest: Codeforces - Codeforces Round 913 (Div. 3)
| URL:     https://codeforces.com/contest/1907/problem/D
| When:    2023-12-05 23:10:44
| 
| Memory:  256 MB
| Time:    5000 ms
*******************************/

/********************************************
|⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠛⠛⠛⠛⠛⠿⣿⣿⣿⣿⣿⣷⠀⣿⣿⣿⣿⣿⣿⣿⣿
|⣿⣿⣿⣿⣿⣿⣿⣿⣿⠛⠉⠀⠀⣠⣤⣤⣤⣤⣤⣤⣤⣀⠀⠉⠛⠿⠈⣦⠙⣿⣿⣿⣿⣿⣿⣿
|⣿⣿⣿⣿⣿⣿⠟⠀⢀⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣤⠀⣼⣿⣦⠙⣿⣿⣿⣿⣿⣿
|⣿⣿⣿⠿⠛⠀⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⣿⣿⣿⠀⠻⣿⣿⣿⣿⣿
|⣿⡟⠀⠀⠤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⣿⣿⣿⠆⠀⠀⠙⣿⣿⣿
|⣿⣆⠀⠀⠀⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠿⢿⠿⠆⠀⠀⠀⠀⣿⣿⣿
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


void solve();
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // cout<< setiosflags(ios::fixed) << setprecision(10);
    int _ = 1; cin>> _; while(_ --)
        solve();
  return 0;
}
#define int long long

void solve() {
    int n, ans = 0;
    cin>> n;
    vector<pair<int, int> > a(n);
    for(int i = 0; i < n; ++ i) {
        cin>> a[i].first >> a[i].second;
    }
    int l = 0, r = 1e9 + 10;
    while((r - l) >= 1) {
        int mid = l + r >> 1, kl = 0, kr = 0;
        bool flag = 1;
        for(int i = 0; i < n; ++ i) {
            if(kl <= a[i].first) {
                if(kr + mid >= a[i].first) kr = min(kr + mid, a[i].second), kl = a[i].first;
                else flag = 0;
            }else if(kr >= a[i].second) {
                if(kl - mid <= a[i].second) kl = max(kl - mid, a[i].first), kr = a[i].second;
                else flag = 0;
            }else if(a[i].first <= kl && kr <= a[i].second) 
                kl = max(kl - mid, a[i].first), kr = min(kr + mid, a[i].second);
            else flag = 0;
        }
        if(flag) r = mid;
        else l = mid + 1;
    }
    cout << l <<endl;
} 
