/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: B. The Walkway
| Contest: Codeforces Round 893 (Div. 2)
| URL:     https://codeforces.com/contest/1858/problem/B
| When:    2023-08-15 22:41:45
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

#define int long long

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
// #define rep(i, a, n) for (int i = a; i <= n; ++i)
// #define per(i, n, a) for (int i = n; i >= a; --i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

const int MAXN = 1000005; // 1e6 + 5
const int INF = 0x3f3f3f3f;
const long long LNF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-7;
const double PI = acos(-1.0);
const int MOD = 1e9 + 7;

void solve() {
    int n, m, d, res = 0, k;
    cin>> n >> m >> d;
    vector<int> s(m + 1), pre(m + 1), rep(m + 1);
    for(int i = 1; i <= m; ++ i) {
        cin>> s[i];
    }
    if(m == 1) {
        cout<< (n - 1) / d + 1 << ' ' << 1 <<endl;
        return;
    }

    for(int i = 1; i <= m; ++ i) {
        if(i == 1) pre[i] = (s[i] == 1 ? 1 : (s[i] - 2) / d + 2);
        else pre[i] = pre[i - 1] + (s[i] - s[i - 1] - 1) / d + 1;
    }
    for(int i = m; i >= 1; -- i) {
        if(i == m) rep[i] = (s[i] == n ? 1 : (n - s[i]) / d + 1);
        else rep[i] = rep[i + 1] + (s[i + 1] - 1 - s[i]) / d + 1;
    }

    map<int, int> ans;
    for(int i = 1; i <= m; ++ i) {
        if(i == 1) {
             k = rep[i + 1] + (s[i + 1] - 2) / d + 1;
        }else if(i == m) {
            k = pre[i - 1] + (n - s[i - 1]) / d;
        }else k = pre[i - 1] + rep[i + 1] + (s[i + 1] - s[i - 1] - 1) / d;
        ans[k] ++;
        // cout<< i << " * " << k <<endl;
    }
    int mi = 2e9, cnt = 0;
    for(auto i:ans) {
        if(i.fi <= mi) mi = i.fi, cnt = i.se;
    }
    cout<< mi << ' ' << cnt <<endl;
    // cout<<endl;
    // for(auto i:ans) cout<< i.fi << ' ' << i.se << endl;
    // for(auto i:pre) cout<< i << " "; cout<< endl;
    // for(auto i:rep) cout<< i << " "; cout<< endl;
}
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1; cin>> _; while(_ --)
        solve();
  return 0;
}
