/*******************************
| Author:  KAZE_mae
| Website: https://cloudfall.top
| Problem: E. Iva &amp; Pav
| Contest: Codeforces Round 900 (Div. 3)
| URL:     https://codeforces.com/contest/1878/problem/E
| When:    2023-09-26 23:16:54
| 
| Memory:  256 MB
| Time:    5000 ms
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

void solve() {
    int n;
    cin>> n;
    vector<int> a(n + 1), st(n);
    vector<vector<int> > p(n);
    vector<pair<int, int> > dk;
    cin>> a[1];
    for(int i = 2; i <= n; ++ i) {
        cin>> a[i];
    }
    int q, k, dl;
    cin>> q;
    for(int i = 0; i < q; ++ i) {
        cin>> dl >> k;
        st[dl - 1] ++;
        dk.push_back({dl, k});
    }
    for(int qq = 0; qq < q; ++ qq) {
        dl = dk[qq].first, k = dk[qq].second;
        st[dl - 1] --;
        if(k > a[dl]) {
            cout<< -1  << " ";
            continue;
        }
        if(p[dl - 1].empty()) {
            p[dl - 1].push_back(a[dl]);  
            for(int j = dl + 1; j <= n && p[dl - 1].back() != 0; ++ j)
                p[dl - 1].push_back((a[j] & p[dl - 1].back()));
        }
        int ans = a[dl], cnt = 0;
        int l = 0, r = p[dl - 1].size() - 1;
        while(l < r) {
            int mid = l + r + 1 >> 1;
            if(p[dl - 1][mid] >= k) l = mid;
            else r = mid - 1;
        }
        cout<< dl + l << " ";
        if(st[dl - 1] == 0) p[dl - 1].clear();
    }
}
signed main() {
    std::ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1; cin>> _; while(_ --)
        solve();
  return 0;
}
