/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: B. Two Binary Strings
| Contest: Educational Codeforces Round 154 (Rated for Div. 2)
| URL:     https://codeforces.com/contest/1861/problem/B
| When:    2023-08-31 22:43:02
| 
| Memory:  256 MB
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

void solve() {
    string a, b;
    cin>> a >> b;
    vector<int> a0, a1, b0, b1;
    for(int i = 1; i < a.size() - 1; ++ i) {
        if(a[i] == '1') a1.push_back(i);
        else a0.push_back(i);
        if(b[i] == '1') b1.push_back(i);
        else b0.push_back(i);
    }
    bool o0 = 0;
    for(int i = 0; i < a.size() - 1; ++ i) {
        if(a[i] == '0' && a[i + 1] == '1' && b[i] == '0' && b[i + 1] == '1') {
            o0 = 1;
            break;
        }
    }
    if(a == b) cout<< "YES" <<endl;
    else if(a1.size() && b1.size() && a1[0] == b[0]) cout<< "YES" <<endl;
    else if(a0.size() && b0.size() && a0.back() == b0.back()) cout<< "YES" <<endl;
    else if(o0) cout<< "YES" <<endl;
    else cout<< "NO" <<endl;
}
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1; cin>> _; while(_ --)
        solve();
  return 0;
}