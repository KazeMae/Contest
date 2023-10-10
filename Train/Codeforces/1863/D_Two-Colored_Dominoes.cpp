/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: D. Two-Colored Dominoes
| Contest: Pinely Round 2 (Div. 1 + Div. 2)
| URL:     https://codeforces.com/contest/1863/problem/D
| When:    2023-08-30 23:55:20
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
#define mkp make_pair
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

char mp[505][505], mp1[505][505];

void solve() {
    int n, m, w = 0, b = 0;
    cin>> n >> m;
    string s;
    for(int i = 0; i < n; ++ i) {
        cin>> s;
        for(int j = 0; j < m; ++ j) mp[i][j] = mp1[i][j] = s[j];
    }
    for(int i = 0; i < n; ++ i) {
        for(int j = 0; j < m; ++ j) {
            if(mp[i][j] == 'U') {
                mp[i][j] = 'B';
                mp[i + 1][j] = 'W';
            }else if(mp[i][j] == 'L') {
                mp[i][j] = 'B';
                mp[i][j + 1] = 'W';
            }
        }
    }
    for(int i = 0; i < n; ++ i) {
        w = 0, b = 0;
        for(int j = 0; j < m; ++ j) {
            if(mp[i][j] == 'W') w ++;
            if(mp[i][j] == 'B') b ++;
        }
        if(w != b) {
            int k = abs(w - b) / 2;
            for(int j = 0; j < m; ++ j) {
                if(mp1[i][j] == 'U') swap(mp[i][j], mp[i + 1][j]), -- k;
                if(k == 0) break;
            }
        }
    }
    for(int j = 0; j < m; ++ j) {
        w = 0, b = 0;
        for(int i = 0; i < n; ++ i) {
            if(mp[i][j] == 'W') w ++;
            if(mp[i][j] == 'B') b ++;
        }
        if(w != b) {
            int k = abs(w - b) / 2;
            for(int i = 0; i < n; ++ i) {
                if(mp1[i][j] == 'L') swap(mp[i][j], mp[i][j + 1]), -- k;
                if(k == 0) break;
            }
        }
    }
    for(int i = 0; i < n; ++ i) {
        w = 0, b = 0;
        for(int j = 0; j < m; ++ j) {
            if(mp[i][j] == 'W') w ++;
            if(mp[i][j] == 'B') b ++;
        }
        if(w != b) {
            cout << -1 <<endl;
            return;
        }
    }
    for(int j = 0; j < m; ++ j) {
        w = 0, b = 0;
        for(int i = 0; i < n; ++ i) {
            if(mp[i][j] == 'W') w ++;
            if(mp[i][j] == 'B') b ++;
        }
        if(w != b) {
            cout << -1 <<endl;
            return;
        }
    }
    for(int i = 0; i < n; ++ i) {
        for(int j = 0; j < m; ++ j) cout<< mp[i][j]; cout << endl;
    }
}
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1; cin>> _; while(_ --) {
        solve();
        // for(int i = 0; i < n; ++ i) {
        //     for(int j = 0; j < m; ++ j) cout<< mp[i][j]; cout <<endl;
        // }
        // cout <<endl;
    }
  return 0;
}
