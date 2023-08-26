/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: Fair Equation
| Contest: NowCoder
| URL:     https://ac.nowcoder.com/acm/contest/57364/M
| When:    2023-08-18 14:33:54
| 
| Memory:  524288 MB
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
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

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

const int N = 1000005; // 1e6 + 5
const int INF = 0x3f3f3f3f;
const long long LNF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-7;
const double PI = acos(-1.0);
const int MOD = 1e9 + 7;

bool is_ok(string y, string x) {
    if(y.size() + 1 != x.size()) return false;
    int cnt = 0;
    for(int i = 0, j = 0; i < y.size() && j < x.size(); ++ i, ++ j) {
        if(y[i] != x[j]) cnt ++, ++ j;
    }
    return cnt == 1;
}

void solve() {
    int a, b, c;
    string p, e, y, x;
    cin>> a >> p >> b >> e >> c;
    y = to_string(a);
    x = to_string(c - b);
    if(is_ok(y, x)) {
        cout<< "Yes" <<endl;
        cout<< x << " " << p << " " << b << " " << e << " " << c <<endl;
        return;
    }
    y = to_string(b);
    x = to_string(c - a);
    if(is_ok(y, x)) {
        cout<< "Yes" <<endl;
        cout<< a << " " << p << " " << x << " " << e << " " << c <<endl;
        return;
    }
    y = to_string(c);
    x = to_string(a + b);
    if(is_ok(y, x)) {
        cout<< "Yes" <<endl;
        cout<< a << " " << p << " " << b << " " << e << " " << x <<endl;
        return;
    }
    cout<< "No" <<endl;
}
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    // int _ = 1; cin>> _; while(_ --)
        solve();
  return 0;
}
